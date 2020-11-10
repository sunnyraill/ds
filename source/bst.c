#include "../include/bst.h"

BSTNode * createNode(int data) {
    BSTNode * root = (BSTNode *)malloc(sizeof(BSTNode)*1);
    root->left = NULL;
    root ->right = NULL;
    root->data = data;
    return root;
}

BSTNode* insertNode(BSTNode * root, int data){
    if(!root)
        return createNode(data);
    
    //find position
    BSTNode * traverse = root;
    BSTNode * prev = NULL;
    while(traverse){
        if(traverse->data < data){
            prev = traverse;
            traverse = traverse->right;
        } else {
            prev = traverse;
            traverse = traverse->left;
        }
    }
    //time to insert node
    if(prev->data < data){
        prev->right = createNode(data);
    } else if (prev->data > data) {
        prev->left = createNode(data);
    }
    return root;
}

BSTNode * createSeqTree() {
    BSTNode * root = NULL;
    int i=0;
    for(i=0;i<10;i++){
        root = insertNode(root, i+1);
    }
    return root;
}

BSTNode * findMinOfBST(BSTNode *root){
    if(!root)
        return NULL;
    
    while(root->left)
        root = root->left;
    
    return root;
    
}

BSTNode * findMaxOfBST(BSTNode *root){
    if(!root)
        return NULL;
    
    while(root->right)
        root = root->right;
    
    return root;
}




BSTNode * createTree() {
    BSTNode * root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(8);
    root->right->left = createNode(5);
    root->right->right = createNode(1);
    BSTNode * node = root->right->left;
    node->right = createNode(7);
    node->right->left = createNode(6);
    return root;
}

void deleteTree(BSTNode * root){
    if(root){
        deleteTree(root->left);
        BSTNode *temp = root->right;
        free(root);
        deleteTree(temp);
    }
}
void inOrderTraverse (BSTNode * root) {
    if(!root)
        return;
    inOrderTraverse(root->left);
    printf("-> %d ",root->data);
    inOrderTraverse(root->right);
}

BSTNode * searchNode(BSTNode * root, int data){
    if(!root){
        return NULL;
    }
    BSTNode * dataNode = root;
    if(root->data < data)
        dataNode = searchNode(root->right, data);
    else if (root->data > data)
        dataNode = searchNode(root->left, data);
    return dataNode;
    
}

BSTNode * deleteNode(BSTNode * root, int data){
    if(!root){
        return NULL;
    }
    BSTNode *origRoot = root;
    BSTNode * prev = NULL;
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
                BSTNode *temp =  root->right ? root->right : root->left;
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

/*int main(){
    BSTNode * root =  createTree();
    inOrderTraverse(root);
    printf(" deleted Node 4 \n");
    deleteNode(root, 4);
    printf(" deleted Success \n");
    inOrderTraverse(root);
    deleteTree(root);
}*/
