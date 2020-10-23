#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

AVLNode * createNode(int data) {
    AVLNode * root = (AVLNode *)malloc(sizeof(AVLNode)*1);
    root->left = NULL;
    root ->right = NULL;
    root->data = data;
    root->height = 0;
    return root;
}

int Height(AVLNode* node){
    return node ? node->height : -1;
}

AVLNode* singleRR(AVLNode* w){
    AVLNode * x = w->right;
    w->right = x->left;
    x->left = w;
    
    //update height
    w->height = MAX(Height(w->left), Height(w->right))+1;
    x->height = MAX(Height(w),Height(x->right))+1;
    return x;
}
AVLNode* singleLL(AVLNode* w){
    AVLNode * x = w->left;
    w->left = x->right;
    x->right = w;
    
    //update height
    w->height = MAX(Height(w->left), Height(w->right))+1;
    x->height = MAX(Height(w),Height(x->right))+1;
    return x;
}

AVLNode* DoubleRL(AVLNode *z){
    z->right = singleLL(z->right);
    return singleRR(z);
    
}
AVLNode * DoubleLR(AVLNode *z){
    z->left = singleRR(z->left);
    return singleLL(z);
}
 

AVLNode* insertAVLNode(AVLNode * root, int data){
    if(!root)
        return createNode(data);
    
    if(root->data < data){
        root->right = insertAVLNode(root->right, data);
        if(Height(root->right) - Height(root->left) > 1) //new node is inserted in right
        { /*need to do rotation */
            //this confirms it either RR or RL case
            //data  here is inserted after root->right
            if(data < root->right->data) //RL case
                root = DoubleRL(root);
            else
                root = singleRR(root);
            
        }
        
    } else if (root->data > data){
        root->left = insertAVLNode(root->left, data);
        if(Height(root->left) - Height(root->right) > 1) //new node is inserted in left branch
        { /*need to do rotation */
            
            if(data > root->left->data) //LR case
                root = DoubleRL(root);
            else
                root = singleRR(root);
        }
    }
    
    root->height = max(Height(root->left), Height(root->right))+1;
    return root;
}

AVLNode * createSeqTree() {
    AVLNode * root = NULL;
    int i=0;
    for(i=0;i<10;i++){
        root = insertAVLNode(root, i+1);
    }
    return root;
}

AVLNode * findMinOfBST(AVLNode *root){
    if(!root)
        return NULL;
    
    while(root->left)
        root = root->left;
    
    return root;
    
}

AVLNode * findMaxOfBST(AVLNode *root){
    if(!root)
        return NULL;
    
    while(root->right)
        root = root->right;
    
    return root;
}



void deleteTree(AVLNode * root){
    if(root){
        deleteTree(root->left);
        AVLNode *temp = root->right;
        free(root);
        deleteTree(root->right);
    }
}
void inOrderTraverse (AVLNode * root) {
    if(!root)
        return;
    inOrderTraverse(root->left);
    printf("-> %d ",root->data);
    inOrderTraverse(root->right);
}

AVLNode * searchNode(AVLNode * root, int data){
    if(!root){
        return NULL;
    }
    AVLNode * dataNode = root;
    if(root->data < data)
        dataNode = searchNode(root->right, data);
    else if (root->data > data)
        dataNode = searchNode(root->left, data);
    return dataNode;
    
}

int BalanceFactor(AVLNode* a, AVLNode * b){
    return Height(a)-Height(b);
}
AVLNode * balance(AVLNode* root){
    if(root) {
        int balanceFactor = Height(root->left)-Height(root->right);
        switch (balanceFactor) {
            case 2:
                if(root->left){//left is more skewed
                    if(Height(root->left->left) > Height(root->left->right)) //LL
                        root = singleLL(root);
                    else if(Height(root->left->left) < Height(root->left->right)) //LR
                        root = DoubleLR(root);
                }
                break;
            case -2:
                if(root->right){//right is more skewed
                    if(Height(root->right->left) < Height(root->right->right)) //RR
                        root = singleRR(root);
                    else if(Height(root->right->left) > Height(root->right->right)) //RL
                        root = DoubleRL(root);
                }
                break;
            default:
                break;
        }
    }
        
    return root;
}
AVLNode * deleteNodeRecursive(AVLNode * root, int data, AVLNode * prev){
    if(!root){
        return NULL;
    }
    if(root->data < data){
        root->right = deleteNodeRecursive(root->right, data, root);
        root = balance(root);
    }
    else if (root->data > data) {
        root->left = deleteNodeRecursive(root->left, data, root);
        root = balance(root);
    }
    else {
        if(root->left && root->right){ // both kids
            root->data = findMaxOfBST(root->left)->data;
            printf(" will be calling itself recursively \n");
            root->left = deleteNodeRecursive(root->left,root->data, root );
        } else if(!prev){
            AVLNode *temp =  root->right ? root->right : root->left;
            free(root);
            root = NULL;
        }else if (root->right){
            if(prev->data > root->data) // node to be deleted is in left side of parent
                prev->left = root->right;
            else
                prev->right = root->right;
            free(root);
            root = NULL;
            
        } else {
            if(prev->data > root->data) // node to be deleted is in left side of parent
                prev->left = root->left;
            else
                prev->right = root->left;
            printf(" will be freeing \n");
            free(root);
            root = NULL;
        }
    }
    
    if (root)
        root->height = MAX(Height(root->right), Height(root->left)) +1 ;
    return root;
}


AVLNode * deleteNode(AVLNode * root, int data){
    if(!root){
        return NULL;
    }
    AVLNode *origRoot = root;
    AVLNode * prev = NULL;
    while(root){
        if(root->data < data){
            prev = root;
            root = root->right;
        }
        else if (root->data > data) {
            prev = root;
            root = root->left;
        }
        else {
            if(root->left && root->right){ // both kids
                root->data = findMaxOfBST(root->left)->data;
                printf(" will be calling itself recursively \n");
                root->left = deleteNode(root->left,root->data );
            } else if(!prev){
                AVLNode *temp =  root->right ? root->right : root->left;
                free(root);
                origRoot=temp;
            }else if (root->right){
                if(prev->data > root->data) // data is in left side
                    prev->left = root->right;
                else
                    prev->right = root->right;
                free(root);
                
            } else {
                if(prev->data > root->data) // data is in left side
                    prev->left = root->left;
                else
                    prev->right = root->left;
                printf(" will be freeing \n");
                free(root);
            }
            break;
        }
    }
    return origRoot;
}

int main(){
    AVLNode * root =  createSeqTree();
    inOrderTraverse(root);
    printf(" deleted Node 4 \n");
    deleteNodeRecursive(root, 4,NULL);
    printf(" deleted Success \n");
    inOrderTraverse(root);
    deleteTree(root);
}

