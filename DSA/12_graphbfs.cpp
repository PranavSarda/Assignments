#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
	int numVertices;
	list<int> *adjLists;
	public:
	Graph(int v)
	{
		numVertices=v;
		adjLists=new list<int>[v];
	}
	void addEdge(int src,int dest)
	{
		adjLists[src].push_front(dest);
		adjLists[dest].push_front(src);
	}
	void bfs(int vertex);
};

void Graph::bfs(int vertex)
{
	cout<<"\nThe BFS Traversal of Graph from "<<vertex<<" is : ";
	int visits=0,*visited,i,current=-1;
	visited=new int[numVertices];
	for(i=0;i<numVertices;i++)
		visited[i]=0;
	list<int>::iterator it;
	queue<int> q;
	q.push(vertex);
	while(visits<numVertices)
	{
		current=q.front();
		q.pop();
		if(visited[current]==0)
		{
			visits++;
			visited[current]=1;
			cout<<current<<" ";
			for(it=adjLists[current].begin();it!=adjLists[current].end();it++)
				q.push(*it);
		}
	}
}

int main()
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.bfs(3);
	
	
	cout<<endl;
	return 0;
}
