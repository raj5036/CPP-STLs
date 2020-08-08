#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<queue>
using namespace std; 

class Graph{
	int V;
	list<int> *adjList;
public:
	Graph(int);
	void addEdge(int,int);
	void BFS(int);
	Graph transpose();
};

Graph::Graph(int V){
	this->V = V;
	adjList=new list<int>[V];
}
void Graph::addEdge(int src,int dest){
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}
void Graph::BFS(int src){
	bool *visited=new bool[V];
	memset(visited,false,V);
	queue<int> q;

	visited[src]=true;
	q.push(src);

	while(!q.empty()){
		int node=q.front();
		std::cout<<node<<" ";
		q.pop();

		list<int>::iterator i;
		for(i=adjList[node].begin();i!= adjList[node].end();++i){
			if(!visited[*i]){
				visited[*i]=true;
				q.push(*i);
			}
		}
	}
}
Graph Graph::transpose(){
	Graph g1;
	
	for(int node=0;node<V;node++){
		list<int>::iterator i;
		for(i=adjList[node].begin();i!= adjList[node].end();++i)
			g1.adjList[*i].push_back(node);
	}
	return g1;
}

int main(){
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3);
	g.BFS(2);

	Graph trans=g.transpose(); 
	trans.BFS(2);
	return 0; 
}