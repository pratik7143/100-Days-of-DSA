#include <stdlib.h>

// Comparator for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place m balls with at least 'dist'
int canPlace(int* position, int n, int m, int dist) {
    int count = 1;  // first ball placed
    int last = position[0];

    for (int i = 1; i < n; i++) {
        if (position[i] - last >= dist) {
            count++;
            last = position[i];
        }
        if (count >= m) return 1;
    }
    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    // Step 1: sort positions
    qsort(position, positionSize, sizeof(int), cmp);

    int left = 1;
    int right = position[positionSize - 1] - position[0];
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            ans = mid;         // possible
            left = mid + 1;    // try bigger distance
        } else {
            right = mid - 1;   // try smaller
        }
    }

    return ans;
}
