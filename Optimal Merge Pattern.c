#include<stdio.h>
void heapify(int a[], int n, int i);
void priqueue(int a[], int n);

void main()
{
    int n,i;
    printf("enter the number of elements:\t");
    scanf("%d",&n);
    int a[10];
    printf("\nenter data:)\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);    
    }
    for(i=n/2; i>=0; i--)
        heapify(a, n, i);
    priqueue(a,n);
    
}
void heapify(int a[], int n, int i)
{
    int temp;
    int small = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l < n && a[small] > a[l])
        small = l;
    if(r < n && a[small] > a[r])
        small = r;
    if(small != i)
    {
        temp = a[i];
        a[i] = a[small];
        a[small] = temp;
        heapify(a,n,small);
    }
}
void priqueue(int a[], int n)
{
    int i,count=0;
    printf("all the costs are costs:\n");
    while(n>1)
    {
        int temp1, temp2, c;
        temp1 = a[0];
        a[0] = a[n-1];
        n = n-1;
         for(i=n/2; i>=0; i--)
             heapify(a, n, i);
         temp2 = a[0];
         c=temp1+temp2;
        printf("%d ",c);
         count = count + c;
         a[0] = c;
        for(i=n/2; i>=0; i--)
            heapify(a, n, i);
    }
    printf("\nThe total cost is %d",count);
    
}
