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
    cout << "popoing from stack : " << Stack->pop() <<std::endl;
    cout<<"printing stack"<<std::endl;
    Stack->printStack();

}
int main(int argc, char **argv){
    cout <<  "hello world" <<endl;
    implementStackUSingLL();
}