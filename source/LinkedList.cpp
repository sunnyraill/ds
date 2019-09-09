#include <LinkedList.hpp>

Node ** LinkedList::getHead(){
    return LinkedList::head;
}
bool LinkedList::addFront(int n){
    bool success = true;
    Node ** head = LinkedList::getHead();
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = n;
    if(newNode == NULL){
        success = false;
        return success; //not enough memeory
    }
    if(*head == NULL){
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
    return success;
}

bool LinkedList::pushBack(int n){
    bool success = true;
    Node ** head = LinkedList::getHead();
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = n;
    if(newNode == NULL){
        success = false;
        return success; //not enough memeory
    }
    if(*head == NULL){
        *head = newNode;
    } else {
        Node * node = *head;
        while(node->next !=NULL){
            node = node->next;
        }
        node->next = newNode;
        newNode->next = NULL;
    }
    return success;
}

int LinkedList::deleteBack(){
    bool success = true;
    Node ** head = LinkedList::getHead();
    int data;
    if(*head == NULL){
        return INT16_MIN; // throwing error is better
    } else {
        Node * current_node = *head, *prev_node = NULL;
        while(current_node->next !=NULL){
            prev_node = current_node;
            current_node = current_node->next;
        }
        if(prev_node != NULL)
            prev_node->next = NULL;
        else // this list has only one node
            *head = NULL;
        data = current_node->data;
        free(current_node);
    }
    return data;
}

int LinkedList::deleteFront(){
    bool success = true;
    Node ** head = LinkedList::getHead();
    int data;
    if(*head == NULL){
        return INT16_MIN; // throwing error is better
    } else {
        Node *prev_node = *head;
        prev_node->next = *head;
        data = prev_node->data;
        free(prev_node);
    }
    return data;
}

int LinkedList::peekFront(){
    if(*(LinkedList::getHead())==NULL)
        return INT16_MIN;
    else 
        return (*(LinkedList::getHead()))->data;

}

void LinkedList::print(){
    Node **top = LinkedList::getHead();
    Node * current = *top;
    while(current != NULL);
    {
        std::cout << current->data << " ==> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}