#include <stdio.h>
#include <limits.h>
#define MAXN 15  // Maximum number of cities
int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int n, int cost[MAXN][MAXN]) {
    int N = 1 << n;
    // dp[mask][i] = minimum cost to reach city i with visited mask
    int dp[1 << MAXN][MAXN];
    // Initialize dp with large values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    // Start from city 0
    dp[1][0] = 0;
    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                
                int newMask = mask | (1 << v);
                
                if (dp[mask][u] != INT_MAX) {
                    dp[newMask][v] = min(
                        dp[newMask][v],
                        dp[mask][u] + cost[u][v]
                    );
                }
            }
        }
    }
    
    int ans = INT_MAX;
    int fullMask = N - 1;
    
    // Return to city 0
    for (int i = 1; i < n; i++) {
        if (dp[fullMask][i] != INT_MAX) {
            ans = min(ans, dp[fullMask][i] + cost[i][0]);
        }
    }
    
    return ans;
}

int main() {
    int n = 4;
    int cost[MAXN][MAXN] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    printf("Minimum TSP cost: %d\n", tsp(n, cost));
    return 0;
}
