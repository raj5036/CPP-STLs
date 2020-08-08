#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<queue>
#include<stack>
using namespace std; 

class Graph{
	int V;
	list<int> *adjList;
	bool detectCycleUtil(int node,bool visited[],bool recStack[]);
public:
	Graph(int);
	void addEdge(int,int);
	void BFS(int);
	bool detectCycle();
};

Graph::Graph(int V){
	this->V = V;
	adjList=new list<int>[V];
}
void Graph::addEdge(int src,int dest){
	adjList[src].push_back(dest);
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

	std::cout<<endl;
}
bool Graph::detectCycle(){
	bool *visited=new bool[V];
	memset(visited,false,V);
	bool *recStack=new bool[V];
	memset(recStack,false,V);

	for(int i=0;i<V;i++)
		if(detectCycleUtil(i,visited,recStack))
			return true;
	return false;
}
bool Graph::detectCycleUtil(int node,bool *visited,bool *recStack){
	if(visited[node]==false){
		visited[node]=true;
		recStack[node]=true;

		list<int>::iterator i;
		for(i=adjList[node].begin();i!= adjList[node].end();++i)
			if(!visited[*i] && detectCycleUtil(*i,visited,recStack))
				return true;
			else if(recStack[*i]==true)
				return true;
	}
	recStack[node]=false;
	return false;
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

	if(g.detectCycle())
		cout<<"Cycle Found"<<endl;
	else
		cout<<"No Cycle Found"<<endl;
	return 0; 
}