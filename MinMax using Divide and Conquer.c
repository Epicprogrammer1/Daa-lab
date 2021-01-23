#include<stdio.h>
#include<limits.h>
int min=INT_MAX,max=INT_MIN;
void minmax(int a[], int l, int h)
{
    if (l == h)
    {
        if (max < a[l])
            max = a[l];
 
        if (min > a[h])
            min = a[h];
 
        return;
    }
    if (h - l == 1)
    {
        if (a[l] < a[h])
        {
            if (min > a[l]) 
                min = a[l];
 
            if (max < a[h])
                max = a[h];
        }
        else
        {
            if (min > a[h])
                min = a[h];
 
            if (max < a[l])
                max = a[l];
        }
        return;
    }
    int mid = (l + h) / 2;
    minmax(a, l, mid);
    minmax(a, mid + 1, h);
}
 
int main()
{
    int n;
    printf("Enter Size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    minmax(a, 0, n - 1);
    printf("Min Element %d",min);
    printf("\nMax element %d",max);
 
    return 0;
}


