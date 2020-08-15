#include<bits/stdc++.h>
#include<array>
using namespace std;

int main(){
	const int size=5;
	std::array<int,size> myArray;
	myArray={1,2,3,5,71};
	
	for(int i=0;i<myArray.size();i++)
		cout<<myArray.at(i)<<" ";
	cout<<endl;

	cout<<myArray.front()<<endl;
	cout<<myArray.back()<<endl;
	
	myArray.fill(-1); //FIll with certain value
	for(int i=0;i<myArray.size();i++)
		cout<<myArray.at(i);

	sort(myArray.begin(),myArray.end());
	return 0;
}
