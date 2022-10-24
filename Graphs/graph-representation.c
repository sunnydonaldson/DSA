#include <stdio.h>

/***********************************************************
* There are four main ways of representing graphs:
* 1. Adjacency matrix
* 2. Adjacency list
* 3. Compact List
* 4. Edge List
***********************************************************/

void adjacencyMatrix()
{
    /*An adjacency matrix for an unweighted graph with 4 nodes looks like this.
    [
        [0, 0, 1, 1],
        [1, 0, 0, 1],
        [1, 1, 0, 1],
        [0, 0, 1, 0],
    ]
    each index in the 2d array corresponds to a connection between 2 nodes.
    So [0][1] is the connection from node 0 to node 1.
    The value at that index is a boolean which tells us whether a connection exists between the two nodes or not.
    (0 meaning False, 1 meaning True)

    Most graph algorithms (when performed on adjacency matrix) take O(n^2) time
    because there are n^2 elements in the matrix.
    */
    int adjacencyMatrix[3][3] = {
        {0, 0, 1},
        {1, 0, 1},
        {0, 1, 0},
    };
    // We can check if a connection from 1 to 2 exists
    printf("connection between node 1 and 2? %d\n", adjacencyMatrix[1][2]);

    // Adjacency matrices can also be used to represent weighted graphs
    // We can use any non-zero value for a weighted connection
    // And zero where there's no conneciton
    // Sunny's note, could we use null instead of zero?  In case zero is a valid weight

    int weightedAdjacencyMatrix[3][3] = {
        {0, 4, 8},
        {8, 0, 2},
        {3, 5, 0},
    };

    printf("Weighted connection between node 2, and 1? %d\n", weightedAdjacencyMatrix[2][1]);
}

int main()
{
    adjacencyMatrix();
    return 0;
}