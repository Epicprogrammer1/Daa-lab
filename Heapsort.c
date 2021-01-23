#include<stdio.h>
#include<stdlib.h>
typedef struct process{
        int bustime;
        int id;
} process;
int *a=NULL;
void adjust(int *a,int root,int n){
        int e=a[root];
        int j;
        for(j=2*root;j<=n;j*=2)
        {
                if(j<n && a[j]<a[j+1])
                        j++;
                if(e>a[j])
                        break;
                a[j/2]=a[j];
        }
        a[j/2]=e;
}
void heapsort(int *a,int n){
        int i;
        for(i=n/2;i>=1;i--)
                adjust(a,i,n);
        for(i=n-1;i>=1;i--)
        {
                int t=a[i];
                a[i]=a[1];
                a[1]=t;
                adjust(a,1,i-1);
        }

}
void display(int *a,int n){
        int i;
		printf("Sorted array : ");
        for(i=1;i<=n;i++){
        	printf("%d\n",a[i]);
        }
}
int create(){
        int i,n;
		printf("Enter the number of the elements: ");
        scanf("%d",&n);
        a=(int *)malloc(sizeof(int)*(n+1));
		printf("Enter the elements: ");
        for(i=1;i<=n;i++)
        {
                scanf("%d",&a[i]);
        }
        return n;
}
int main(){
        int n=create();
        display(a,n);
        heapsort(a,n);
        display(a,n);
}
