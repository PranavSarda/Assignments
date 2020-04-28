#include<iostream>
using namespace std;
#define MAX 10
#define INFINITY 1000


int main()
{
	int n,graph[MAX][MAX],mst[MAX][MAX],cost[MAX][MAX],visited[MAX],i,j;
	//graph[MAX][MAX] is Adjacency Matrix of Graph and mst[MAX][MAX] is that of Min. Spanning Tree
	//And cost matrix to help calculate mst from graph
	//visited[i] will store the visited vertices
	cout<<"\nEnter the Number of Nodes in the Graph : ";
	cin>>n;
	cout<<"\nEnter the Adjacency Matrix of Graph :- \nNote:Please make sure that all the Nodes are connected to the Graph.\nNote:Weights should be less than 1000.\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>graph[i][j];
			if(graph[i][j]!=0)
				cost[i][j]=graph[i][j];
			else
				cost[i][j]=INFINITY;
			mst[i][j]=0;
		}
		visited[i]=0;
		graph[i][i]=0;	//Eliminate Self Loops
		cost[i][i]=INFINITY;
	}
			
	int mini,minj,visits=0,mind,weight=0;
	visited[0]=1;
	visits++;
	while(visits<n)
	{
		mini=-1;
		minj=-1;
		mind=INFINITY;
		for(i=0;i<n;i++)
		{
			if(visited[i])
			{
				for(j=0;j<n;j++)
				{
					if(cost[i][j]<mind && !visited[j])
					{
						mini=i;
						minj=j;
						mind=cost[i][j];
					}
				}
			}
		}
		weight+=mind;
		mst[mini][minj]=cost[mini][minj];
		mst[minj][mini]=cost[minj][mini];
		visited[minj]=1;
		
		visits++;
	}
	
	cout<<"\nThe Minimum Spanning Tree has a Weight of : "<<weight<<endl;
	cout<<"\nThe Minimum Spanning Tree is :- \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<mst[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	return(0);
}
