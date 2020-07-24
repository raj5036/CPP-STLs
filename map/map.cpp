#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<iterator>
#include<set>
#include<map>
using namespace std;
int main(){
	map<int,int> hash;
	hash.insert(pair<int,int>(1,23));
	hash.insert(pair<int,int>(2,12));
	hash.insert(pair<int,int>(3,11));

	map<int,int>::iterator it;
	for(it=hash.begin();it!=hash.end();it++)
		cout<<"key "<< it->first <<" value "<<it->second<<endl;
}