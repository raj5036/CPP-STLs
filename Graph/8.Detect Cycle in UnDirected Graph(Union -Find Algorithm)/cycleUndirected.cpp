#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<queue>
using namespace std;

class Edge{
public:
		int src,dest;
		Edge(int,int);
};
class Graph{
public:
	int V;
	list<int> *edge;
	list<int> *adjList;
	void union(int parent[],int src,int dest);
	int find(int node,int parent[]);
	Graph(int,int);
	void addEdge(int,int);
	bool UnionFind();
};

Edge::Edge(int src,int dest){
	this->src=src;
	this->dest=dest;
}
Graph::Graph(int V,int E){
	this->V = V;
	adjList=new list<int>[V];
	edge=new list<int>[V];
}
void Graph::addEdge(int u,int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}
void Graph::union(int parent[],int src,int dest){
	int xSet=find(src,parent);
	int ySet=find(dest,parent);
	if(xSet!=ySet)
		parent[xSet]=ySet;
}
int Graph::find(int i,int *parent){
	if(parent[i]==-1)
		return i;
	return find(parent[i],parent);
}
bool Graph::UnionFind(){
	int parent[V];
	memset(parent,-1,V);

	for(int i=0;i<E;i++){
		int src=edge[i].src;
		int dest=edge[i].dest;

		if(find(src,parent)==find(dest,parent))
			return true; 
		union(parent,src,dest);
	}
	return false;
}

int main(){
	return 0;
}