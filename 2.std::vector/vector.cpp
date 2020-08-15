#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
	vector<int> v;
	//To reserve a specific size of the vector so that the system doesn't go through a lot of workload which causes due to dynamic resizing of the vector.It saves time
	v.reserve(10);

	
	for(int i=1;i<=10;i++)
		v.push_back(i);

	for(int i=0;i<v.size();i++)
		cout<<v.at(i)<<" ";
	cout<<endl;
	
	cout<<"Size "<<v.size()<<endl;
	cout<<"Capacity "<<v.capacity()<<endl;
	v.shrink_to_fit();
	cout<<"Capacity after shrinking(shrink_to_fit) "<<v.capacity()<<endl;

	cout<<"front "<<v.front()<<endl;
	cout<<"Back "<<v.back()<<endl;

    	v.pop_back(); // removes last element 

	vector<int> myvector={ 1, 2, 3, 4, 5 }; 
    	vector<int>::iterator it; 
  
    	it = myvector.begin(); 
    	myvector.erase(it); 
  
    	// Printing the Vector 
    	for (auto it = myvector.begin(); it != myvector.end(); ++it) 
		cout << ' ' << *it; 
	return 0;
}
