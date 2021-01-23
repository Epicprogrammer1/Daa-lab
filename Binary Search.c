#include <stdio.h> 
int binarySearch(int a[], int l, int h, int key) 
{ 
	if (h >= l) { 
		int mid = l + (h - l) / 2; 
		if (a[mid] == key) 
			return mid; 
		if (a[mid] > key) 
			return binarySearch(a, l, mid - 1, key); 
		return binarySearch(a, mid + 1, h, key); 
	} 
	return -1; 
} 

int main(void) 
{ 
    int i,n,key;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in Array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
	int result = binarySearch(a, 0, n - 1, key); 
	(result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result); 
	return 0; 
} 
