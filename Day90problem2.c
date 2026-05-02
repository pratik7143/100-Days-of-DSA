#include <limits.h>

// Helper function to check if we can split into <= k subarrays
int canSplit(int* nums, int numsSize, int k, int maxSum) {
    int count = 1;  // at least one subarray
    int currentSum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (currentSum + nums[i] <= maxSum) {
            currentSum += nums[i];
        } else {
            count++;
            currentSum = nums[i];
        }
    }
    return count <= k;
}
int splitArray(int* nums, int numsSize, int k) {
    int left = INT_MIN, right = 0;
    // find max element and total sum
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > left) left = nums[i];
        right += nums[i];
    }
    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            right = mid - 1;  // try smaller
        } else {
            left = mid + 1;   // need larger
        }
    }
    return ans;
}
