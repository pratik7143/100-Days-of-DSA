int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // Peak is on the right
            left = mid + 1;
        } else {
            // Peak is on the left (including mid)
            right = mid;
        }
    }

    return left;  // or right (both same here)
}
