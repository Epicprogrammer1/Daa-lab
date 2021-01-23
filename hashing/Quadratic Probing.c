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
    insert(1);
    insert(2);
    insert(21);
    search(21);
}
