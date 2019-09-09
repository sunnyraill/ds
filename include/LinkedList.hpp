#include<iostream>
#include "myStack.hpp"
// struct Node_s {
//     int data;
//     struct Node_s* next;
// };
// typedef Node_s Node;
#ifndef LINKED_LIST
#define LINKEDLIST

class LinkedList {
        
    public:
        Node ** head;
        Node ** getHead();
        bool addFront(int n);
        bool pushBack(int n);
        int deleteFront();
        int deleteBack();
        int peekFront();
        void print();
        LinkedList(){
            head = (Node**)malloc(sizeof(Node*));
        }
};
#endif
