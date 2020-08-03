#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int> *adjList;
public:
	Graph(int);
	void addEdge(int,int);
	void BFS(int);
};

Graph::Graph(int V){
	this->V=V;
	adjList=new list<int>[V];
}

void Graph::addEdge(int src,int dest){
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

void Graph::BFS(int src){
	bool visited[V];
	memset(visited,false,V);
	queue<int> q;
	visited[src]=true;
	q.push(src);

	list<int>::iterator i;
	while(!q.empty()){
		int node=q.front();
		std::cout<<node<<" ";
		q.pop();

		for(auto i=adjList[node].begin();i!=adjList[node].end();i++)
			if(!visited[*i]){
				visited[*i]=true;
				q.push(*i);
			}
	}
}
int main(){
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
	return 0;
}
