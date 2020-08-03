#include<iostream>
#include<bits/stdc++.h> 
#include<vector>
using namespace std;
void addEdge(vector<int> adjList[],int src,int dest){
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}
void printGraph(vector<int> adjList[],int V){
	for(int i=0;i<V;i++){
		std::cout<<"Adjecency List of "<<i<<" is";
		for(auto j:adjList[i])
			cout<<j<<"->";
		std::cout<<endl;
	}
} 
int main(){
	int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, V); 
	return 0;
}