#ifndef AVL_H
#define AVL_H

typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

AVLNode* insertAVLNode(AVLNode * root, int data);

AVLNode * findMinOfBST(AVLNode *root);
AVLNode * findMaxOfBST(AVLNode *root);
AVLNode * searchNode(AVLNode * root, int data);

//pass prev as NULL
AVLNode * deleteNodeRecursive(AVLNode * root, int data, AVLNode * prev);

void inOrderTraverse (AVLNode * root);
void deleteTree(AVLNode * root);


#endif
