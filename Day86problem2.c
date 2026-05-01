int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int left = 1, right = x, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Avoid overflow: use mid <= x / mid instead of mid*mid <= x
        if (mid <= x / mid) {
            ans = mid;        // possible answer
            left = mid + 1;   // try bigger
        } else {
            right = mid - 1;  // go smaller
        }
    }

    return ans;
}
