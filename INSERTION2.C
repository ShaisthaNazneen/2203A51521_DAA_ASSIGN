#include <stdio.h>
#include <stdlib.h>
void sortAsc(int a[],int size);
void sortDes(int a[],int size);
void sortAsc(int a[],int size) {
    int i, j, temp;
    for (i=1;i<size;i++) {
        temp = a[i];
        j=i-1;
        while (j>=0 && a[j]>temp) {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}
void sortDes(int a[], int size) {
    int i,j,temp;
    for (i=1;i<size;i++) {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]<temp) {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1] =temp;
    }
}
int main() {
    int times[100];
    int i,SIZE;
    char choice;
    printf("Enter the number of times: ");
    if (scanf("%d", &SIZE) !=1) { 
        printf("Invalid input for number of times!\n");
        return 1;
    }
    
    printf("Enter time to reach destination:\n");
    for (i=0; i<SIZE; i++) {
        if (scanf("%d", &times[i]) != 1) { 
            printf("Invalid input for time!\n");
            return 1;
        }
    }
    printf("Sort in ascending or descending order? (a/d): ");
    scanf(" %c", &choice);
    if (choice == 'a') {
        sortAsc(times, SIZE);
    } else if (choice == 'd') {
        sortDes(times, SIZE);
    } else {
        printf("Invalid choice!\n");
        
        return 1;
    }
    printf("Sorted times:\n");
    for (i=0;i<SIZE;i++) {
        printf("%d\n", times[i]);
    }
    
    return 0;
}
