#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<list>
using namespace std;

class Graph{
	int V;
	int time;
	list<int> *adjList;
	void DFSUtil(int v,bool visited[]);
public:
	Graph(int);
	void addEdge(int,int);
	void DFS(int);
};

Graph::Graph(int V){
	this->V = V;
	adjList=new list<int>[V];
	time=0;
}
void Graph::addEdge(int u,int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}
void Graph::DFS(int src){
	bool *visited=new bool[V];
	memset(visited,false,V);

	DFSUtil(src,visited);
}
void Graph::DFSUtil(int node,bool visited[]){
	visited[node]=true;
	std::cout<<node<<" was visited at "<<time++<<endl;
	list<int>::iterator i;
	for(i=adjList[node].begin();i!= adjList[node].end();++i)
		if(!visited[*i])
			DFSUtil(*i,visited);
	std::cout<<node<<" came out on "<<time++<<endl;
}
int main(){
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3);

	g.DFS(2);
	return 0; 
}