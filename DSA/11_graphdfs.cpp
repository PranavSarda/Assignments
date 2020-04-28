#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph
{
	int numVertices;
	list<int> *adjLists;
	public:
	Graph(int v)
	{
		numVertices=v;
		adjLists=new list<int>[numVertices];
	}
	void addEdge(int src,int dest)
	{
		adjLists[src].push_front(dest);
		adjLists[dest].push_front(src);
	}
	void dfs(int vertex);
};

stack<int> s;

void Graph::dfs(int vertex)
{
	cout<<"\nThe DFS Traversal of given Graph is : ";
	list<int>::iterator it;
	int i,visits=0,current,currentAdj;
	int *visited;			//Didnt store visited array unnecessarily in class but locally!!!
	visited=new int[numVertices];
	for(i=0;i<numVertices;i++)
		visited[i]=0;
//	cout<<vertex<<" ";
//	visited[vertex]=1;	//Tab of nodes visited
//	visits++;		//Number of Nodes visited
//	current=vertex;
	s.push(vertex);
	while(visits<numVertices)
	{
		current=s.top();
		s.pop();
		if(visited[current]==0)
		{
			cout<<current<<" ";
			visited[current]=1;
			visits++;
			for(it=adjLists[current].begin();it!=adjLists[current].end();it++)
			{
				s.push(*it);
			}
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
	g.dfs(3);
	
	
	return 0;
}
