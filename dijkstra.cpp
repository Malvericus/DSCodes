#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

// Class to represent a node and its weight in the priority queue
class Pair {
public:
    int node;
    int weight;
    Pair(int weight, int node) {
        this->node = node;
        this->weight = weight;
    }
};

// Custom comparator for the priority queue (min-heap)
struct Compare {
    bool operator()(Pair const& p1, Pair const& p2) {
        return p1.weight > p2.weight;
    }
};

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S) {
    // Min-heap to store the nodes and their current distances
    priority_queue<Pair, vector<Pair>, Compare> pq;
    vector<int> distance(V, INT_MAX);

    distance[S] = 0;
    pq.push(Pair(0, S));

    while (!pq.empty()) {
        int node = pq.top().node;
        int wt = pq.top().weight;
        pq.pop();

        // Traverse all adjacent nodes
        for (auto it : adj[node]) {
            int adjnode = it.first;
            int edgewt = it.second;

            int newdistance = wt + edgewt;
            if (newdistance < distance[adjnode]) {
                distance[adjnode] = newdistance;
                pq.push(Pair(newdistance, adjnode));
            }
        }
    }

    return distance;
}

int main() {
    int V = 6, S = 0;
    vector<vector<pair<int, int>>> adj(V);

    // Edge list {u, v, w}
    int edges[][3] = {{0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {2, 3, 3}, {2, 5, 6}, {2, 4, 1}, {3, 5, 2}, {4, 5, 3}};
    
    // Building the adjacency list
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
    }

    vector<int> result = dijkstra(V, adj, S);

    // Output the distances from the source node
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << " : " << result[i] << endl;
    }

    return 0;
}