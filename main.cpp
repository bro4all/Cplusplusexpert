#include<iostream>
#include <stringVector.h>
struct Node{
    int data;
    Node* next;
};
Node head;
void insert(int d){
    Node* temp= new Node();
    temp->data=d;
    temp->next=nullptr;
    if (head==NULL){
        head=temp;
        return ;

    }
    Node* temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
}