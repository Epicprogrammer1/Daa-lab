#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node{
   int data;
   struct node *left;
   struct node *right;
} node;
node *head=NULL;
int sum=0;
void quicksort(node *a[],int first,int last){
   int i, j, pivot;
   node *temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]->data<=a[pivot]&&i<last)
            i++;
         while(a[j]->data>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);
   }
}
void insert(node *data){
   node *temp=(node *)malloc(sizeof(node));
   /*Initalization of second node for string data(the parameter passsed to the function)*/
   temp->right=temp1;
   temp->data=head->data+data;
   temp->left=head;
   head=temp;
}
int mincomputations(node *head){
   if(head){
      if(head->right && head->left){
         sum+=head->data;
        printf("%d  ",head->data);
      }
      mincomputations(head->right);
      mincomputations(head->left);
   }
}
int construct(node *a[],int n){
   quicksort(a,0,n-1);
   if(n==1)
      return a[0]->data;
   else{
      int  i;
      for(i=0;i<n-1;i++){
         head=a[i];
         quicksort(a,1,n-1);
         insert(a[i+1]);
      }
   }
}
void main(){
    int n,i,j,m,tapes[MAX][MAX];
    node **a=(node **)malloc(sizeof(node *)*n);
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        a[i]=(node *)malloc(sizeof(node));
        scanf("%d",&a[i]->data);
        a[i]->left=a[i]->right=NULL;
    }
    construct(a,n);
    mincomputations(head);
    printf("\nMin: %d",sum);
}