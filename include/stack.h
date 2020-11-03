
#ifndef MY_STACK_H
#define MY_STACK_H
typedef struct Node_s {
    int data;
    struct Node_s * next;
} Node;

typedef struct Stack_s {
    Node * head;
} Stack;

int isStackEmpty(Stack *s);
int isStackFull(Stack *s);

void push(Stack *s, int data);
int pop (Stack *s);
int peek(Stack *s);

void printStack(Stack *s);
Stack* CreateStack();
void deleteStack(Stack *s);

#endif
