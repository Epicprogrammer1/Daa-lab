#include<stdio.h>
#include<string.h>
#include<stdio.h>
int max(int a, int b){
    return a>b?a:b;
}
void lcs( char *s1, char *s2, int m, int n ) 
{ 
    int L[m+1][n+1]; 
    for (int i=0; i<=m; i++) 
    { 
    	for (int j=0; j<=n; j++) 
    	{ 
    	if (i == 0 || j == 0) 
    		L[i][j] = 0; 
    	else if (s1[i-1] == s2[j-1]) 
    		L[i][j] = L[i-1][j-1] + 1; 
    	else
    		L[i][j] = max(L[i-1][j], L[i][j-1]); 
    	} 
    } 
    int index = L[m][n]; 
    char lcs[index+1]; 
    lcs[index] = '\0'; 
    int i = m, j = n; 
    while (i > 0 && j > 0) 
    { 
    	if (s1[i-1] == s2[j-1]) 
    	{ 
    		lcs[index-1] = s1[i-1]; 
    		i--; j--; index--;	 
    	} 
    	else if (L[i-1][j] > L[i][j-1]) 
    		i--; 
    	else
    		j--; 
    } 
    printf("LCS : %s",lcs); 
} 
int main() 
{ 
    char s1[10000],s2[10000];
    printf("Enter String 1:");
    scanf("%s",s1);
    printf("Enter String 2:");
    scanf("%s",s2);
    int m = strlen(s1); 
    int n = strlen(s2); 
    lcs(s1, s2, m, n); 
return 0; 
}
