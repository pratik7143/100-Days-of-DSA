#include <stdlib.h>
typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void heapifyUp(KthLargest* obj, int i){
    while(i > 0){
        int parent = (i - 1) / 2;
        if(obj->heap[parent] > obj->heap[i]){
            swap(&obj->heap[parent], &obj->heap[i]);
            i = parent;
        } else break;
    }
}
void heapifyDown(KthLargest* obj, int i){
    while(1){
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;
        if(right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if(smallest != i){
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        } else break;
    }
}
void insert(KthLargest* obj, int val){
    obj->heap[obj->size] = val;
    obj->size++;
    heapifyUp(obj, obj->size - 1);
}
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->k = k;

    for(int i = 0; i < numsSize; i++){
        if(obj->size < k){
            insert(obj, nums[i]);
        }
        else if(nums[i] > obj->heap[0]){
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {

    if(obj->size < obj->k){
        insert(obj, val);
    }
    else if(val > obj->heap[0]){
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
