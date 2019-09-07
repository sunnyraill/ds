#include<iostream>

struct Node_s {
    int data;
    struct Node_s* next;
};
typedef struct Node_s Node;

class Mystack {
    private:
        
    public:
        Node** head;
        Node * getHead();
        bool push(int val);
        int pop();
        int peek();
        void printStack();
        Mystack(){
            head = (Node**) malloc(sizeof(Node**));
            *head = NULL;  
        }
        ~Mystack(){
            //Node * curr = *head;
            //free()
        }

};