#include<iostream>

struct Node_s {
    int data;
    struct Node_s* next;
};
typedef struct Node_s Node;

class Mystack {
    private:
        Node** head;
        Node * getHead();
    public:
        bool push(int val);
        int pop();
        int peek();
        void printStack();
        // Mystack(){
        //     head = (Node**) malloc(sizeof(Node**));
        //     *head = NULL;  
        // }
        // ~Mystack(){
        //     //Node * curr = *head;
        //     //free()
        // }

};