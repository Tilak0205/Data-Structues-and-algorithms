#include<stdio.h>
#include<stdlib.h>
#define n 7
////////////////////////////////////////////////////////////////////////////////
int graph[n][n]={0};
int q[20]={0},visited[20]={0},i,j,f=0,r=-1,v;

bfs(int v)
{
    q[++r]=v;
    visited[v]=1;
    while(f<=r)
    {
    	v=q[f++];
    	printf("%d ",v);
    	for(i=1;i<=n;i++)
    	{
    		if(graph[v][i] && visited[i]==0){
    			q[++r]=i;
    			visited[i]=1;
			}
		}
	}
}
int vs[10]={0};
void dfs(int u){
	if(vs[u]==0){
		printf("%d ",u);
		vs[u]=1;
		for(int i=1;i<=n;i++){
			if(graph[u][i]==1 && vs[i]==0){
				dfs(i);
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
	addedge(graph,1,4);
	addedge(graph,2,1);
	addedge(graph,2,3);
	addedge(graph,3,1);
	addedge(graph,3,2);
	addedge(graph,3,4);
	addedge(graph,3,5);
	addedge(graph,4,1);
	addedge(graph,4,3);
	addedge(graph,4,5);
	addedge(graph,5,4);
	addedge(graph,5,3);
	addedge(graph,5,6);
	addedge(graph,5,7);
	addedge(graph,6,5);
	addedge(graph,7,5);
	print(graph);
	printf("\n");
	bfs(6);
	printf("\n");
	dfs(6);
}


