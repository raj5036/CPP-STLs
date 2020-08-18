#include<bits/stdc++.h>
#include<deque>
using namespace std;

void showDQ(deque<int>& dq){
	deque<int>::iterator it;
	for(it=dq.begin();it!=dq.end();++it)
		std::cout<<*it<<" ";
}
int main(){
	std::deque<int> dq;
	deque<int>::iterator it;
	for(int i=1;i<=10;i++)
		dq.push_back(i);
	showDQ(dq);
	dq.push_front(0);
	std::cout<<"After push front"<<endl;
	showDQ(dq);
	std::cout<<"Checking erase"<<endl;
	for(it=dq.begin();it!=dq.end();++it)
		if(*it==5)
			dq.erase(it);
	showDQ(dq);
	dq.clear();
	return 0;
}
