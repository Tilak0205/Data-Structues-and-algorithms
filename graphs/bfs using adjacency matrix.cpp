#include<stdio.h>
#include<stdlib.h>
#define n 7
////////////////////////////////////////////////////////////////////////////////
int graph[n][n]={0};
int q[20]={0},visited[20]={0},i,j,f=-1,r=-1,v;

bfs(int v)
{
	f++;
	q[++r]=v;
	visited[v]=1;
	while(f<=r)
	{
		v=q[f++];
		printf("%d ",v);
		for(i=1;i<=n;i++)
		{
			if(graph[v][i] && !visited[i])
			{
				q[++r]=i;
				visited[i]=1;
			}
		}
	}
}

addedge(int graph[][n],int i,int j)
{
	graph[i][j]=1;
}

print(int graph[n][n])
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	addedge(graph,1,2);
	addedge(graph,1,3);
	addedge(graph,2,1);
	addedge(graph,2,4);
	addedge(graph,3,1);
	addedge(graph,3,4);
	addedge(graph,4,2);
	addedge(graph,4,3);
	addedge(graph,4,5);
	addedge(graph,4,6);
	addedge(graph,5,4);
	addedge(graph,6,4);
	print(graph);
	printf("\nThe bfs of the graph using adjacency matrix is \n");
	bfs(2);
}


