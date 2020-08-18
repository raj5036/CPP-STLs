#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
	vector<int> v;
	for(int i=0;i<5;i++)
		v.push_back(rand());
	cout<<"is_sorted "<<is_sorted(v.begin(),v.end())<<endl;
	sort(v.begin(),v.end());
	cout<<"is_sorted "<<is_sorted(v.begin(),v.end())<<endl;

	//Sort in descending order
	sort(v.begin(),v.end(),greater<int>());
	cout<<"is_sorted in descending order "<<is_sorted(v.begin(),v.end(),greater<int>())<<endl;

	vector<int>::iterator i;
	for(i=v.begin();i!=v.end();i++)
		cout<<*i<<" ";
	return 0;
}
