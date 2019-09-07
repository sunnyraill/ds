#include<stdio.h>
#include<myStack.hpp>

bool Mystack::push(int n){
    Node *newNode = NULL;
    bool success=false;
    
    newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        success = false;
    }
    
    newNode->data = n;
    newNode->next = *head;
    *head = newNode;
    success = true;
    return success;

}
Node * Mystack::getHead(){
    return *head;
}

void Mystack::printStack(){
    Node * currentNode = *Mystack::head;
    while( currentNode != NULL){
        int d = currentNode->data;


        printf("%d ==>",d);
        //std::cout << "==>" << d;
        currentNode = currentNode->next;
    }
}

int Mystack::pop(){
    if(Mystack::head == NULL){
        return INT16_MIN;
    }
    Node * currentNode = *Mystack::head;
    *Mystack::head= (*Mystack::head)->next;
    int data = currentNode->data;
    free(currentNode);
    return data;
}

int Mystack::peek(){
    if(Mystack::head == NULL){
        return INT16_MIN;
    }
    return Mystack::getHead()->data;
}