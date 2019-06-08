#include <iostream>

/*

An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, 
it holds a field named both, which is an XOR of the next node and the previous node. 
Implement an XOR linked list; 
it has an add(element) which adds the element to the end, 
and a get(index) which returns the node at index.

 */

class Node;

Node* XOR(Node* a,Node* b){
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
};

class Node{
    public:
        int val;
        Node* nextPtr;
        Node(int val,Node* prev,Node* next){
            this->val = val;
            this->nextPtr = XOR(prev,next);
        }
        Node* getNext(Node* prev){
            return XOR(prev,this->nextPtr);
        }
};

void add(Node* &head,int val);

int get(int index, Node* current);
void printList(Node* head);

int main(){
    Node* head = NULL;
    add(head,3);
    add(head,4);
    add(head,5);
    add(head,7);

    std::cout << get(0,head) << std::endl;
    std::cout << get(1,head) << std::endl;
    std::cout << get(2,head) << std::endl;

    return 0;
}

int get(int index, Node* current){
    Node* prev = NULL;
    while(index && current!=NULL){
        Node* next = XOR(prev,current->nextPtr);
        prev = current;
        current = next;
        index--;
    }
    return current->val;
}
void printList(Node* head){
    Node* current = head;
    Node* pre = NULL;
    Node* next;

    while(current!=NULL){
        std::cout << current->val << std::endl;
        next = XOR(pre,current->nextPtr);
        pre = current;
        current = next;
    }
}

void add(Node* &head,int val){
    if(head == NULL){
        head = new Node(val,NULL,NULL);
    }
    else{
        Node* prev = NULL;
        Node* current = head;
        Node* next = XOR(prev,current->nextPtr);
        while(next!=NULL){
            prev = current;
            current = next;
            next = XOR(prev,current->nextPtr);
        }
        Node* node = new Node(val,current,NULL);
        current->nextPtr = XOR(prev,node);
    } 
}