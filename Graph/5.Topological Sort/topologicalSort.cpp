#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<stack>
using namespace std; 

class Graph{
	int V;
	list<int> *adjList;
	void util(int v,bool visited[],stack<int> s);
public:
	Graph(int);
	void addEdge(int,int);
	void topologicalSort(int);
};

Graph::Graph(int V){
	this->V = V;
	adjList=new list<int>[V];
}
void Graph::addEdge(int u,int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}
void Graph::topologicalSort(int src){
	bool *visited=new bool[V];
	memset(visited,false,V);
	stack<int> s;

	util(src,visited,s);

	while(!s.empty()){
		std::cout<<s.top()<<" ";
		s.pop();
	}
}
void Graph::util(int node,bool visited[],stack<int> s){
	visited[node]=true;
	std::cout<<node<<" ";
	list<int>::iterator i;
	for(i=adjList[node].begin();i!= adjList[node].end();++i)
		if(!visited[*i])
			util(*i,visited,s);
	s.push(node);
}
int main(){
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3);

	g.topologicalSort(2);
	return 0; 
}