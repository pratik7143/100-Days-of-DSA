#include <stdlib.h>
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int *deque = (int*)malloc(numsSize * sizeof(int)); // store indices
    int front = 0, rear = -1;
    int idx = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(front <= rear && deque[front] <= i - k)
            front++;
        // Remove smaller elements from rear
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;
        // Add current index
        deque[++rear] = i;
                if(i >= k - 1)
            result[idx++] = nums[deque[front]];
    }
    *returnSize = numsSize - k + 1;
    free(deque);
    return result;
}
