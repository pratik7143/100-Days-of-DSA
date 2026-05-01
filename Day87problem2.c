int canEat(int* piles, int pilesSize, int h, int k) {
    long long hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k;  // ceil division
    }

    return hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1, right = 0;

    // Find max pile (upper bound)
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right) right = piles[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canEat(piles, pilesSize, h, mid)) {
            ans = mid;          // possible answer
            right = mid - 1;    // try smaller k
        } else {
            left = mid + 1;     // need bigger k
        }
    }

    return ans;
}
