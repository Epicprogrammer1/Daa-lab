#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void printParenthesis(int i, int j, int n, int* bracket)
{
    if (i == j) {
        printf("A%d",i);
        return;
    }
 
    printf("(");
    printParenthesis(i, *((bracket + i * n) + j), n,bracket);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n,bracket);
    printf(")");
}
void matrixChainOrder(int p[], int n)
{
    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++) 
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) 
            {
                int q = m[i][k] + m[k + 1][j]
                        + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) 
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    printf("Optimal Parenthesization is : ");
    printParenthesis(1, n - 1, n, (int*)bracket);
   printf("\nCost is: %d",m[1][n - 1]);
}
 
// Driver code
int main()
{
    int n;
    printf("Enter Size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    matrixChainOrder(a,n);
    return 0;
}