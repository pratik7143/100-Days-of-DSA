#include <stdio.h>
int linearSearch(int arr[], int n, int key, int *comparisonCount) {
    *comparisonCount = 0;  
    
    for (int i = 0; i < n; i++) 
    {
        (*comparisonCount)++;  
        
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;  
}

void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n, key, result, comparisons;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    displayArray(arr, n);
    
    // Input search key
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    
    result = linearSearch(arr, n, key, &comparisons);
    printf("Number of comparisons: %d\n", comparisons);
    if (result != -1) {
        printf("Element %d found at index %d (position %d)\n", key, result, result + 1);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    
    return 0;
}