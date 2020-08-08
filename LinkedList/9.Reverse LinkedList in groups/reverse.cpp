#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

Node* reverseInGroups(Node* head,int K){
	Node* prev=NULL;
	Node* current=head;
	Node* next=NULL;
	int count=0;
	while(current!=NULL && count<K){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	if(next!=NULL)
		head->next=reverse(next,K);
	return prev;
}

int main(){
    Node *head=new Node(1);
    for(int i=2;i<=5;i++)
        head->appendNode(head,i);
    head->printList(head);
    return 0;
}
