#include <limits.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int maxSum = INT_MIN, currentMax = 0;
    int minSum = INT_MAX, currentMin = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        totalSum += x;

        // Kadane for max subarray
        currentMax = (currentMax + x > x) ? currentMax + x : x;
        maxSum = (maxSum > currentMax) ? maxSum : currentMax;

        // Kadane for min subarray
        currentMin = (currentMin + x < x) ? currentMin + x : x;
        minSum = (minSum < currentMin) ? minSum : currentMin;
    }

    // If all elements are negative
    if (maxSum < 0)
        return maxSum;

    // maximum of normal and circular cases
    int maxCircular = totalSum - minSum;
    return (maxSum > maxCircular) ? maxSum : maxCircular;
}
