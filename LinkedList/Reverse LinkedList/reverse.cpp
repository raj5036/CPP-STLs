#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    int data;
    Node* next;
public:
    Node(int);
    void appendNode(Node*,int);
    Node* reverse(Node*);
    void printList(Node*);
};
Node::Node(int x){
    data=x;
    next=NULL;
}
void Node::appendNode(Node* head,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* last=head;
    while(last->next!=NULL)
        last-last->next;
    last->next=newNode;
}
Node* Node::reverse(Node* head){
    Node* prev=NULL;
    Node* cur=head;
    Node* next=NULL;
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;

        prev=cur;
        cur=next;
    }
    Node* newhead=prev;
    return newhead;
}
void Node::printList(Node* head){
    Node* current=head;
    while(current!=NULL){
        std::cout<<current->data<<"->";
        current=current->next;
    }
}
int main(){
    Node *head=new Node(1);
    for(int i=2;i<=5;i++)
        head->appendNode(head,i);
    head->printList(head);
    return 0;
}