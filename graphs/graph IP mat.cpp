#include<stdio.h>
int graph[20][20],q[20],visited[20],i,j,n,f=0,r=-1,v;

bfs(int v)
{
    for(i=1;i<=n;i++)
    {
        if(graph[v][i] && !visited[i]){
            q[++r]=i;
        }
    }
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[++f]);
    }
}

int main()
{
    printf("enter the number of vertieces: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++){
        	scanf("%d",&graph[i][j]);
		}
    }
    for(i=1;i<=n;i++)
    {
    	q[i]=0;
    	visited[i]=0;
	}
    printf("Starting vertx: ");
    scanf("%d",&v);
    bfs(v);
    for(i=1;i<=n;i++)
    {
        if(visited[i])
        {
            printf("%d ",i);
        }
    }
}
