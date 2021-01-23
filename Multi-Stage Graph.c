#include<stdio.h> 
#include<stdlib.h>
#include<limits.h>
int shortestdistance(int graph[1000][1000],int n) { 
	int dist[1000]; 
	dist[n-1] = 0; 
	for (int i = n-2 ; i >= 0 ; i--) 
	{ 
		dist[i] = INT_MAX; 
		for (int j = i ; j < n ; j++) 
		{ 
			if (graph[i][j] == INT_MAX) 
				continue; 
			dist[i] = dist[i]<graph[i][j] + dist[j]?dist[i]:(graph[i][j] + dist[j]); 
		} 
	} 

	return dist[0]; 
} 
int main() 
{ 
	int graph[1000][1000],i,j,n;
	printf("Enter Rows or Columns: ");
	scanf("%d",&n);
	printf("Enter Adjacecny Matrix (Enter number < 0 for INF)");
	for(i=0;i<n-1;i++)
	    for(j=0;j<n;j++){
	        scanf("%d",&graph[i][j]);
	        if(graph[i][j]<0)
	            graph[i][j]=INT_MAX;
	    }
	    printf("\n");
	for(i=0;i<n-1;i++){
	    for(j=0;j<n;j++){
	        printf("%3d",graph[i][j]);
	    }
	    printf("\n");
	}
	printf("Shortest Distance: %d",shortestdistance(graph,n)); 
	return 0; 
} 
