#include <iostream>

using namespace std;

class DisjointSet {
    vector<int> parent, size;

    public: DisjointSet(int V) {
        parent.resize(V);
        size.resize(V, 1);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }

    int findRootParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findRootParent(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int rootParent_u = findRootParent(u);
        int rootParent_v = findRootParent(v);

        if (rootParent_u == rootParent_v) {
            return;
        }

        if (size[rootParent_u] < size[rootParent_v]) {
            parent[rootParent_u] = rootParent_v;
            size[rootParent_v] += size[rootParent_u];
        } else {
            parent[rootParent_v] = rootParent_u;
            size[rootParent_u] += size[rootParent_v];
        }
    }
};

class Edge {
    public: int source, dest, wt;
    Edge(int source, int dest, int wt) : source(source), dest(dest), wt(wt) {}
};

bool compare(Edge a, Edge b) {
    return a.wt < b.wt;
}

int kruskals(int V, vector<vector<pair<int, int>>> &adj) {
    vector<Edge> edges;

    // Extract edges from adjacency list
    for (int i = 0; i < V; i++) {
        for (auto &it : adj[i]) {
            int adjnode = it.first;
            int wt = it.second;

            edges.emplace_back(i, adjnode, wt);
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    DisjointSet ds(V);

    int sum = 0;

    // Process each edge
    for (auto &edge : edges) {
        int u = edge.source;
        int v = edge.dest;
        int wt = edge.wt;

        if (ds.findRootParent(u) != ds.findRootParent(v)) {
            sum += wt;
            ds.unionBySize(u, v);
        }
    }

    return sum;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    // Convert edge list to adjacency list
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int sum = kruskals(V, adj);
    cout << "The min sum of all the edge weights: " << sum << endl;

    return 0;
}