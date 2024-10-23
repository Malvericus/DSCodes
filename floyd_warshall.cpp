#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void floydWarshallAlgorithm(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Initializing the adjacency matrix: set all unreachable edges to infinity (1e9), and diagonal to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e9;  // Large value to represent infinity
            }
            if (i == j) {
                matrix[i][j] = 0;
            }
        }
    }

    // Floyd-Warshall algorithm: updating shortest paths through intermediate nodes
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] < 1e9 && matrix[k][j] < 1e9) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // After updating, set unreachable paths back to -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }
}

int main() {
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, -1)); // Initialize the adjacency matrix

    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    floydWarshallAlgorithm(matrix);

    // Output the resulting matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}