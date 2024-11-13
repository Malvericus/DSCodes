#include <iostream>
using namespace std;

using namespace std;

class Dijkstra {

    public: vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(V, INT_MAX);

        distance[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjnode = it[0];
                int edgewt = it[1];

                if (dis + edgewt < distance[adjnode])
                {
                    distance[adjnode] = dis + edgewt;
                    pq.push({distance[adjnode], adjnode});
                }
            }
        }

        return distance;
    }
};

// edges = { {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {2, 3, 3}, {2, 5, 6}, {2, 4, 1}, {3, 5, 2}, {4, 5, 3} };
int main() {
    int V, E, S;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];
    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Add the edge to adjacency list
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // If the graph is undirected
    }

    cout << "Enter source vertex: ";
    cin >> S;

    Dijkstra d;
    vector<int> result = d.dijkstra(V, adj, S);

    cout << "Shortest distances from source node " << S << ":\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}