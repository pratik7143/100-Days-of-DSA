#include <stdio.h>
#include <limits.h>
#include <string.h>
int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    // Initialize distances with a large value (infinity)
    int dist[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    // Run the relaxation k + 1 times
    for (int i = 0; i <= k; i++) {
        int temp[n];
        memcpy(temp, dist, sizeof(dist));

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int price = flights[j][2];

            // If the source of the flight is reachable
            if (dist[u] != INT_MAX) {
                if (dist[u] + price < temp[v]) {
                    temp[v] = dist[u] + price;
                }
            }
        }
        // Update the main dist array with the results of this iteration
        memcpy(dist, temp, sizeof(dist));
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}
