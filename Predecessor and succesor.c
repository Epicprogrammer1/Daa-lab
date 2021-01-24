#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *l;
    struct node *r;
} node;
node *pre=NULL,*suc=NULL;
node *root=NULL;
int visited[100]={0};
node *traversed[100];
int len=0;
void findPreSuc(node* root, int data) 
{ 

    if (root == NULL)  return ; 

    if (root->data == data) 
    { 
        if (root->l != NULL) 
        { 
            node* tmp = root->l; 
            while (tmp->r) 
                tmp = tmp->r; 
            pre = tmp ; 
        } 
        if (root->r != NULL) 
        { 
            node* tmp = root->r ; 
            while (tmp->l) 
                tmp = tmp->l ; 
            suc = tmp ; 
        } 
        return ; 
    } 
    if (root->data > data) 
    { 
        suc = root ; 
        findPreSuc(root->l, data) ; 
    } 
    else
    { 
        pre = root ; 
        findPreSuc(root->r,data) ; 
    } 
} 
void insert(int data){
        node *p=root;
        node *temp=(node *)malloc(sizeof(node));
        temp->l=NULL;
        temp->r=NULL;
        temp->data=data;
        if(!root){
                root=temp;
        }else{
                node *pp=NULL;
                while(p){
                pp=p;
                if(p->data<data){
                        p=p->r;
                }
                else if(p->data>data){
                        p=p->l;
                        }
                else{
                        printf("\nDuplicate elements");
                        return ;
                }
                
                }
        if(pp->data<data)
                pp->r=temp;
        else if(pp->data>data){
                pp->l=temp;
                }
        }
        
}

void main(){
    int ch=1;
    int ele;node* res=NULL;
    printf("1.Insert\n");
    printf("2.Inorder Sucessor\n");
    printf("3.Exit\n");
    while(1){
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter element to be inserted: ");scanf("%d",&ele);insert(ele);break;
            case 2: printf("Enter inoder sucessor to be found: "),scanf("%d",&ele);;
                    // res=search(ele);
                    pre=NULL;
                    suc=NULL;
                    findPreSuc(root,ele);
                    if (pre != NULL) 
                      printf("\nPredecessor is %d\n",pre->data);
                    else
                      printf("\nNo Predecessor\n"); 
                  
                    if (suc != NULL) 
                      printf("Successor is %d",suc->data); 
                    else
                      printf("No Successor"); 
                    return 0; break;
            case 3: return;
        }
    }
}
