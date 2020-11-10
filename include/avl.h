#ifndef AVL_H
#define AVL_H

typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

AVLNode* insertAVLNode(AVLNode * root, int data);

AVLNode * findMinOfAVLBST(AVLNode *root);
AVLNode * findMaxOfAVLBST(AVLNode *root);
AVLNode * searchAVLNode(AVLNode * root, int data);

//pass prev as NULL
AVLNode * deleteAVLNodeRecursive(AVLNode * root, int data, AVLNode * prev);

void inOrderTraverseAVL (AVLNode * root);
void deleteAVLTree(AVLNode * root);


#endif
