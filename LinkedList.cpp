#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){}
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* head = NULL;
Node* curr = NULL;

Node* createNode(int data){ return new Node(data);}

void insertAtFirst(int data){

    Node* newNode = createNode(data);

    if(head == NULL){
        head = newNode;
        curr = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void insertAtLast(int data){
    if(head == NULL){
        insertAtFirst(data);
    }
    else{
        curr->next = createNode(data);
        curr = curr->next;
    }
}


void insertAfter(int after, int data){
    Node* temp = head;

    if(head != NULL){
        while(temp->next!=NULL && temp->data != after){
            temp = temp->next;
        }
        if(temp->next!=NULL){
        Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        }
    }
}

void display(){
    Node* temp = head;
    while( temp !=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}


int main(){
    insertAtFirst(7);
    insertAtFirst(8);
    insertAtFirst(15);
    insertAtLast(30);
    insertAfter(30,200);

    display();


return 0;
}




