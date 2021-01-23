#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
    int start;
    int end;
    int weight;
} edge;
int parent[100];
int find(int parent[],int i){
    if(parent[i]==-1)
        return i;
    find(parent,parent[i]);
}
void union1(int parent[],int x,int y){
    int xset=find(parent,x);
    int yset=find(parent,y);
    if(xset!=yset){
        parent[xset]=yset;
    }
}
void kruskal(edge a[],int n,int size){
    int nodecount=0,cost=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j].weight>a[j+1].weight){
                edge temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    for(int i=0;i<n && nodecount!=size-1;i++){
        if(find(parent,a[i].start)!=find(parent,a[i].end)){
            union1(parent,a[i].start,a[i].end);
            cost+=a[i].weight;
            nodecount++;
        }
    }
    printf("Cost: %d",cost);
}
int main(){
        int i,j,src,n,size;
    printf("enter num of vertices:\t");
    scanf("%d",&size);
    printf("Enter the number of edges: ");
    scanf("%d",&n);
    edge a[100];
    for(i=0;i<n;i++)
        scanf("%d %d %d",&a[i].start,&a[i].end,&a[i].weight);
    for(i=0;i<100;i++)
        parent[i]=-1;
    kruskal(a,n,size);
}
