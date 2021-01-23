#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define SIZE 25
//#include<_mingw.h>
void display(int *a,int);
int hash(int x,int n){
    return x%n;
}
void insert(int a[],int visited[],int x,int n){
    int loc=hash(x,n);
    //printf("%d\n",loc);
    if(visited[loc]==0){
        visited[loc]=1;
        a[loc]=x;
        }
    else{
        int i=loc+1;
        while(i!=loc){
            if(i>=n){
                i=i-n;
            }
            if(!visited[i]){
                visited[i]=1;
                a[i]=x;
                return;
            }
            i++;
        }
        if(i==loc)
            printf("Overflow");
    }
    //display(a,n);
    //printf("\n");
}
void display(int a[],int n){
    int i=0;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
/*
x - the element to be searched
a - Hash table
*/
int search(int a[],int visited[],int x,int n){
    int loc=hash(x,n);
    if(a[loc]==x)
        return loc;   
    int i=loc+1;
    while(visited[i] && i!=loc){
        if(i>=n){
            i=i-n;
        }
        if(a[i]==x)
            return i;
        i++;
    }
    if(!visited[i] || i==loc)
        return -1;
}
void main(){
    int ch=0,x=0;
    int n=SIZE;
    int a[SIZE]={0},visited[SIZE]={0};
    
    printf("\n1.insert\n2.display\n3.Search\n4.exit");
    do{
        display(visited,n);
        printf("\nEnter Option: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element: ");scanf("%d",&x);insert(a,visited,x,n);break;
            case 2: printf("The Hashtable is: ");display(a,n);break;
            case 3:printf("Enter the element to be searched: ");scanf("%d",&x);printf("%d",search(a,visited,x,n)); 
            case 4:return;break;
        }
    }while(ch!=4);
}
