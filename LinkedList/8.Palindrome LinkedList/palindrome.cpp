#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool palindrom(Node* head){
	stack<int> s;
	Node* current=head;
	while(current!=NULL){
		s.push(current->data);
		current=current->next;
	}
	current=head;
	while(current!=NULL){
		if(current->data!=s.top())
			return false;
		s.pop();
		current=current->next;
	}
	return true;
}
int main(){
    Node *head=new Node(1);
    for(int i=2;i<=5;i++)
        head->appendNode(head,i);
    head->printList(head);
    return 0;
}
