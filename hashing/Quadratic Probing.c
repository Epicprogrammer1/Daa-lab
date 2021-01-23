#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int availabe[SIZE]={0};
int elecnt=0;
int table[SIZE]={0};
int hash(int x){
    return x%SIZE;
}
int insert(int x){
    int pos=hash(x);
    if(elecnt==SIZE){
        printf("\nFULL");
        return -1;
    }
    if(availabe[pos]){
        int i=0;
        while(i<SIZE*SIZE){
            pos=(hash(pos+pos*pos));
            if(!availabe[pos]){
                table[pos]=x;
                availabe[pos]=1;
                printf("\n%d at %d pos in hash table",x,pos);
                return pos;
            }
            i++;
        }
    }else{
        printf("\n%d at %d pos in hash table",x,pos);
        table[pos]=x;
        availabe[pos]=1;
        return pos;
    }
}
int search(int x){
        int i=0;
        int pos=hash(x%SIZE);
        if(x==table[pos]){
            printf("\n%d at %d pos in hash table",x,pos);
            return pos;
        }
        while(i<SIZE*SIZE){
            pos=(hash(pos+pos*pos));
            if(x==table[pos]){ 
                printf("\n%d at %d pos in hash table",x,pos);
                return pos;
            }
            i++;
        }   
        printf("Not Found");
        return -1;
}
void display(){
    int i;
    printf("\nHashtable is:");
    for(i=0;i<SIZE;i++)
        printf("%d ",table[i]);
}
void main(){
    int ch,x;
    printf("\n1.hinsert\n2.display\n3.Search\n4.exit");
    do{
        printf("\nEnter Option: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element: ");scanf("%d",&x);insert(x);break;
            case 2: printf("The Hashtable is: \n");display();break;
            case 3: printf("Enter element to be searched");
                    int key;
                    scanf("%d",&key);
                    int res=search(key);
                    res!=-1?printf("It is present in hashtable at %d",key):printf("Element not present");break;
            //case 3:printf("Enter the element to be searched: ");scanf("%d",&x);printf("%d",search(a,x,n)); 
            case 4:return;break;
        }
    }while(ch!=3);
}
