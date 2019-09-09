#include<iostream>
#include <myStack.hpp>
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
int main(int argc, char **argv){
    cout <<  "hello world" <<endl;
    implementStackUSingLL();
}