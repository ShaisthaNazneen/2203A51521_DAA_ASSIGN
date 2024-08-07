#include <stdio.h>
#include <stdlib.h>
void merge(int* a, int low, int mid, int high, int order)
 {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int* L = (int*)malloc(n1 *sizeof(int));
    int* R = (int*)malloc(n2 *sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = a[low + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
    i = 0; 
    j = 0; 
    k = low; 
    while (i < n1 && j < n2)
	 {
        if (order==0) 
		{
            if (L[i]<=R[j]) 
			{
                a[k]=L[i];
                i++;
            }
			else 
			{
                a[k]=R[j];
                j++;
            }
        } 
		else 
		{ 
            if (L[i] >= R[j]) 
			{
                a[k]=L[i];
                i++;
            }
			 else 
			{
                a[k]=R[j];
                j++;
            }
        }
        k++;
    }
    while (i < n1) 
	{
        a[k] =L[i];
        i++;
        k++;
    }
    while (j < n2) 
	{
        a[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void mergeSort(int* arr, int low, int high, int order) 
{
    if (low < high) 
	{
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, order);
        mergeSort(arr, mid + 1, high, order);
        merge(arr, low, mid, high, order);
    }
}
int main() 
{
    int n, order;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int* a = (int*)malloc(n*sizeof(int));
    printf("Enter the product IDs");
    int i;
    for (i=0;i<n;i++) 
	{
        scanf("%d",&a[i]);
    }
    printf("Enter 0 for ascending order and 1 for descending order: ");
    scanf("%d", &order);
    mergeSort(a,0,n - 1,order);
    printf("\nSorted array is: \n");
    for (i = 0; i < n; i++) 
	{
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}
