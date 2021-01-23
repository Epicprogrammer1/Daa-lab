#include<stdio.h>
#include<stdlib.h>
int dist[100];
visited[100]={0};
int mindistance(){
    int min=__INT_MAX__,min_index;
    for(int i=0;i<n;i++){
        if(visited[i]==0 && dist[i]<=min)
        {
            min=dist[i];
            min_index=i;
        }
    }
}

void dijkstra(int src){

    for(i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(i=0;i<n;i++){
        int u=mindistance();
        for(j=0;j<n;j++)
        {
            if(!vis[j] && g[u][j] && dist[u]+g[u][j]<dist[j])
                dist[j]=dist[u]+g[u][j];
        }
    }
    printf("vertex\tdistance from source");
    for(i=0; i<n; i++)
    {
        printf("%d\t\t%d\n",i,dist[i]);
    }
}
void main()
{
    int i,j,src;
    printf("enter num of vertices:\t");
    scanf("%d",&n);
    printf("\nenter the adjacency matrix:\t");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&g[i][j]);
    printf("\nenter the source vertex:\t");
    scanf("%d",&src);
    dijkstra(src);
}
