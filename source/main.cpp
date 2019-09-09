#include<iostream>
#include <myStack.hpp>
#include <LinkedList.hpp>
using namespace std;

void implementStackUSingLL(){
    Mystack *Stack= new Mystack();
    Stack->push(10);
    Stack->push(5);
    Stack->push(8);
    Stack->push(17);
    Stack->printStack();
    cout << "peeking stack : " << Stack->peek()<< std::endl;
    cout << "popping from stack : " << Stack->pop() <<std::endl;
    cout<<"printing stack"<<std::endl;
    Stack->printStack();
    delete Stack;
}

void reverseLinkList(){
    LinkedList *llist= new LinkedList();
     llist->pushBack(10);
     llist->pushBack(5);
     llist->pushBack(8);
     llist->pushBack(17);
     llist->print();
     llist->reverse();
     llist->print();
}

int main(int argc, char **argv){
    cout <<  "hello world" <<endl;
    reverseLinkList();
}