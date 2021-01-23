#include<stdio.h>
#include<stdlib.h>
typedef struct hnode{
    int data;
    struct hnode *next;
} hnode;
void display(hnode **a,int n){
    int i;
    for(i=0;i<n;i++){
        hnode *p=a[i];
        while(p){
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}
int hash(int x,int n){
    return x%n;
}
void hinsert(hnode **a,int x, int n){
    int i=hash(x,n);
    hnode *p=a[i];
    hnode *temp=(hnode *)malloc(sizeof(hnode));
    temp->data=x;
    temp->next=NULL;
    if(!a[i]){
        a[i]=temp;
    }
    else{
        while(p->next){
            p=p->next;
        }
        p->next=temp;
    }
}
//bool search(hnode **a )
void main(){
    int n=100; 
    int ch=0,x=0;
    int i=0;
    hnode *a[100];
    for(i=0;i<n;i++)
    {
        a[i]=NULL;
    }
    printf("\n1.hinsert\n2.display\n3.exit");
    do{
        printf("\nEnter Option: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element: ");scanf("%d",&x);hinsert(a,x,n);break;
            case 2: printf("The Hashtable is: \n");display(a,n);break;
            //case 3:printf("Enter the element to be searched: ");scanf("%d",&x);printf("%d",search(a,x,n)); 
            case 3:return;break;
        }
    }while(ch!=3);
}
