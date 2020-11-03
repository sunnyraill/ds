#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#include "../include/stack.h"


int isStackEmpty(Stack *s){
    if(!s)
        return 1;
    if(!s->head)
        return 1;
    
    return 0;
}
int isStackFull(Stack *s){
    return 0;
}

void push(Stack *s, int data){
    if(!s)
        return;
    else {
    
        Node * newNode = (Node*)malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Not enough memory !\n");
            return;
        }
        
        newNode->data = data;
        newNode->next = s->head;
        s->head = newNode;
        return;
    }
}

int pop (Stack *s){
    int temp = INT_MIN;
    if(!s)
        return temp;
    if(s->head){
        Node * tempNode = s->head;
        s->head = s->head->next;
        temp = tempNode->data;
        free(tempNode);
    } else {
        printf("stack is empty \n");
    }
    return temp;
}

int peek(Stack *s){
    
    if(!isStackEmpty(s))
        return s->head->data;
    
    return INT_MIN;
}
void printStack(Stack *s){
    if(!s)
        return;
    if(!isStackEmpty(s)){
        Node * current = s->head;
        while(current){
            printf(" --> %d ",current->data);
            current = current->next;
        }
    } else {
        printf("stack is empty \n");
    }
}

Stack* CreateStack(){
    Stack * stack = (Stack*)malloc(1 * sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void deleteStack(Stack *s){
    if(!s)
        return;
    if(!isStackEmpty(s)){
        while(s->head){
            Node * temp = s->head;
            s->head = s->head->next;
            free(temp);
            temp = NULL;
        }
    }
    free(s);
}

/*
int main(){
    Stack *s = CreateStack();
    for(int i=0;i<100;i++)
        push(s,i);
    printStack(s);
    for(int i=0;i<20;i++)
        pop(s);
    printStack(s);
    return 0;
} */
