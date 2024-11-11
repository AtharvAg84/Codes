#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with the minimum distance value
int minDistance(int* dist, int* sptSet, int V) {
    int min = INT_MAX, min_index;
    
    // Search for the vertex with the smallest distance that is not yet processed
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's Algorithm to find the shortest path from a source node
void dijkstra(int** graph, int V, int src) {
    // Dynamically allocate distance array and sptSet array
    int* dist = (int*)malloc(V * sizeof(int));  // Store the shortest distance from source to each node
    int* sptSet = (int*)malloc(V * sizeof(int));  // Mark visited nodes
    
    // Initialize distances as infinity and sptSet as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance to the source vertex is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist[] of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if the current edge weight offers a shorter path
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }

    // Free dynamically allocated memory
    free(dist);
    free(sptSet);
}

int main() {
    int V;  // Number of vertices
    int src;  // Source vertex

    // Ask the user for the number of vertices and the source vertex
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    // Dynamically allocate memory for the adjacency matrix
    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }

    // Ask the user to enter the graph edges and weights
    printf("Enter the adjacency matrix (0 for no edge, other values for edge weight):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run Dijkstra's algorithm
    dijkstra(graph, V, src);

    // Free dynamically allocated memory for the graph
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
