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

int main() {
    int V = 6, S = 0;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges = { {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {2, 3, 3}, {2, 5, 6}, {2, 4, 1}, {3, 5, 2}, {4, 5, 3} };

    for (auto it : edges) {
        vector<int> temp(2);
        temp[0] = it[1];
        temp[1] = it[2];
        adj[it[0]].push_back(temp);
    }

    Dijkstra d;
    vector<int> result = d.dijkstra(V, adj, S);

    for (int i = 0; i < result.size(); i++)
    {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}