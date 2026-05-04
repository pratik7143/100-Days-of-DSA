#include <stdio.h>
#include <stdlib.h>
// Heapify function
void heapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}
void insert(int heap[], int *size, int val, int k) {
    heap[*size] = val;
    (*size)++;

    int i = *size - 1;
    // Fix min heap
    while (i != 0 && heap[(i-1)/2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }

    // If size > k, remove smallest
    if (*size > k) {
        heap[0] = heap[*size - 1];
        (*size)--;
        heapify(heap, *size, 0);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int heap[k];
    int size = 0;

    for (int i = 0; i < numsSize; i++) {
        insert(heap, &size, nums[i], k);
    }

    return heap[0]; // kth largest
}
