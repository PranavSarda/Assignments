#include<iostream>
using namespace std;
# define MAX 10
#define INFINITY 1000

void dijkstra(int graph[MAX][MAX],int n,int start);

int main()
{
	int graph[MAX][MAX],n,start,i,j;
	cout<<"\nEnter the Number of Vertices in your Graph : ";
	cin>>n;
	cout<<"\nEnter the Adjacency Matrix of the Graph : ";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>graph[i][j];
	
	cout<<"\nEnter the Node you want to start from : ";
	cin>>start;
	dijkstra(graph,n,start);
	
	return 0;
}

void dijkstra(int graph[MAX][MAX],int n,int start)
{
	int cost[MAX][MAX],visited[MAX],prev[MAX],distance[MAX];
	//cost[MAX][MAX] will store the cost between nodes
	//visited will store the visited edges
	//pred will store the previous node for shortest paths reference
	//distance stores the current distance of all nodes from start
	int mindistance=INFINITY,nextnode,i,j,visits=0;
	//visits will store the number of nodes covered
	//mindistance will store the min distance of a node for each repetition
	//nextnode will store node with min distance in each repetition
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(graph[i][j]==0 || i==j)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=graph[i][j];
				
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		prev[i]=start;
		distance[i]=cost[start][i];
	}
	visited[start]=1;
	visits++;
	distance[start]=0;
	
	while(visits<n)
	{
		mindistance=INFINITY;
		for(i=0;i<n;i++)
			if(visited[i]==0)
				if(mindistance>distance[i])
				{
					nextnode=i;
					mindistance=distance[i];
				}
		visited[nextnode]=1;
		visits++;
		for(i=0;i<n;i++)
			if(visited[i]==0)
				if(distance[i]>(mindistance+cost[nextnode][i]))
				{
					distance[i]=mindistance+cost[nextnode][i];
					prev[i]=nextnode;
				}
	}
	
	cout<<"\nThe Minimum Distances from "<<start<<" to the various vertices are :-\n";
	for(i=0;i<n;i++)
	{
		cout<<"\nVertex "<<i<<" : "<<distance[i];
		cout<<"\nPath : "<<i<<" ";
		j=i;
		while(j!=start)
		{
			cout<<prev[j]<<" ";
			j=prev[j];
		}
	}
		
}
