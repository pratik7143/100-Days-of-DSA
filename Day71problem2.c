#include <stdlib.h>
#include <limits.h>
int abs_val(int x) {
    return x < 0 ? -x : x;
}
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    // If there's 1 or 0 points, the cost to connect them is 0
    if (pointsSize <= 1) {
        return 0;
    }
    // minDist tracks the shortest distance from the current MST to unvisited points
    int* minDist = (int*)malloc(pointsSize * sizeof(int));
    // visited tracks which points are already in our MST
    int* visited = (int*)calloc(pointsSize, sizeof(int));
    int totalCost = 0;
    // Initialize minimum distances to infinity (INT_MAX)
    for (int i = 0; i < pointsSize; i++) {
        minDist[i] = INT_MAX;
    }
    
    // Start building the MST from the 0th point
    int currNode = 0;
    visited[0] = 1;
    
    // We need to add pointsSize - 1 edges to connect all points
    for (int step = 0; step < pointsSize - 1; step++) {
        int minEdge = INT_MAX;
        int nextNode = -1;
        
        // Update distances to unvisited nodes from the newly added node
        for (int i = 0; i < pointsSize; i++) {
            if (!visited[i]) {
                // Calculate Manhattan distance between currNode and unvisited node 'i'
                int dist = abs_val(points[currNode][0] - points[i][0]) + 
                           abs_val(points[currNode][1] - points[i][1]);
                
                // Update the shortest known distance to node 'i' if this new path is better
                if (dist < minDist[i]) {
                    minDist[i] = dist;
                }
                
                // Find the absolute minimum edge to expand our MST
                if (minDist[i] < minEdge) {
                    minEdge = minDist[i];
                    nextNode = i;
                }
            }
        }
        // Add the closest unvisited node to our MST
        totalCost += minEdge;
        visited[nextNode] = 1;
        currNode = nextNode;
    }
    
    // Free allocated memory
    free(minDist);
    free(visited);
    
    return totalCost;
}
