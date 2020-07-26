#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<iterator>
using namespace std;

int main(){
	set<int,greater <int> > s;
	s.insert(12);
	s.insert(1);
	s.insert(32);
	s.insert(45);
	s.insert(1);

	set<int,greater<int> >::iterator it;
	for(it=s.begin();it!=s.end();it++)
		cout<<*it<<" ";
	cout<<endl;

	set<int,greater<int> > s2(s.begin(),s.end()); //********
	for(it=s2.begin();it!=s2.end();it++)
		cout<<*it<<" ";
	cout<<endl;

	int n=s2.erase(45);
	cout<<n;

	cout<<*s.upper_bound(32)<<endl;
	cout<<*s.lower_bound(32)<<endl;

	cout<<"SIze of s2 "<<s2.size()<<endl;
	set.clear();

	//Looking for a element
	int key=3;
	if(s.find(3)==s.end())
		cout<<"Key not present"<<endl;
	else
		cout<<"Key found"<<endl;
	return 0;
}