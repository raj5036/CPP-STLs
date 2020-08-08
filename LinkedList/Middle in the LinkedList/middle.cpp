#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
Node* findMiddle(Node* head){
    Node* fast=head,slow=head;
    while(fast->next!=NULL and fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
    Node *head=new Node(1);
    for(int i=2;i<=5;i++)
        head->appendNode(head,i);
    head->printList(head);
    return 0;
}