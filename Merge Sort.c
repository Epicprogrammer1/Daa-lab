#include<stdio.h>
//int a[10]={40,98,78,778,67,85,27,3,82,11};
int n;
void merge(int *a,int l,int m,int h){
/*
    The function merge take 4 parameters 
    a-integr array 
    l- is the starting of list 1
    m- is the ending index of list1
        and j+1 is the satring index of list 2
    h- is the ending of list 2
    and the return void
*/
    int b[100];
    int i=l,j=m+1,k=0;
    while (i<=m && j<=h)
        {
            if(a[i]<a[j]){
                b[k++]=a[i++];
        }
        else
        {
                b[k++]=a[j++];
        }
    }
    while(j<=h){
        b[k++]=a[j++];
    }
    while(i<=m){
        b[k++]=a[i++];
    }
    for(i=l,j=0;i<=h;i++,j++){
        a[i]=b[j];
    }
}
void mergeSort(int *a,int l,int h){
    int i=0;
    /*The function mergeSort takes 3 parameters
    a[]- The array to be sorted
    l-Starting index of the list
    h-Ending index of the list*/
    if(l<h){
        int mid=(l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
void main(){
    //driver code
    int i,a[10];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);
    printf("Sorted Array:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
} 
