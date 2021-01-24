//FRACTINAL KNAPSACK USING RATIO

#include<stdio.h>
#define max 100

typedef struct item
{
    int profit;
    int wt;
    float ratio;
}item;

item k[max];

void sort(int n)
{
    int i,j;
    item temp;
    for(i=0; i<n; i++)
        for(j=0 ; j<n-i-1; j++)
        {
            if(k[j].ratio < k[j+1].ratio)
            {
                temp = k[j];
                k[j] = k[j+1];
                k[j+1] = temp;
            }
        }
}
void main()
{
    int n,i,j=0,capacity;
    float prof=0;
    float k1[max];
    printf("enter number of items:\t");
    scanf("%d",&n);
    printf("\nenter the capacity of the knapsack:\t");
    scanf("%d",&capacity);
    printf("enter profit : weight\n");
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&k[i].profit, &k[i].wt);
        k[i].ratio = (float)k[i].profit/k[i].wt;
    }
    sort(n);
    
    for(i=0; i<n; i++)
    {
        if(capacity > 0)
        {
            if(capacity < k[i].wt)
            {
                k1[j] = k[i].profit*capacity/k[i].wt;       
                j++;
                capacity = 0;
            }
            else
            {
                k1[j] = k[i].profit;
                j++;
                capacity = capacity - k[i].wt;
            }
        }
    }
        for(i=0; i<j; i++)
        {
            printf("%f ",k1[i]);
            prof = prof + k1[i]; 
        }
    printf("\nmaximum profit is %f",prof);
    
}
