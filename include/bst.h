#ifndef MY_BST_H
#define MY_BST_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;


BSTNode* insertNode(BSTNode * root, int data);
void deleteTree(BSTNode * root);

void inOrderTraverse (BSTNode * root);

BSTNode * searchNode(BSTNode * root, int data);
BSTNode * deleteNode(BSTNode * root, int data);
BSTNode * findMinOfBST(BSTNode *root);
BSTNode * findMinOfBST(BSTNode *root);


#endif
