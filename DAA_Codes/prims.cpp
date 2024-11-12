#include <iostream> 

using namespace std; 

class Prims {
    
    public: int prims_algorithm(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int , int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(V, 0);

        pq.push({0, 0}); // pushing wt = 0 for node = 0
        int sum = 0;

        while (!pq.empty()) {
            
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop(); 

            if (visited[node] == 1)
            {
                continue;
            }
            
            visited[node] = 1;
            sum += wt;
            for (auto it : adj[node])
            {
                int adjnode = it[0];
                int edgewt = it[1];
                if (!visited[adjnode])
                {
                    pq.push({edgewt, adjnode});
                }
                
            }
        }

        return sum;
    }
};

int main() {

    int V = 5;
    vector<vector<int>> edges = { {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2} };
    vector<vector<int>> adj[V];

    for(auto it : edges) {
        vector<int> temp(2);
        // u -> {v, w}
        temp[0] = it[1];
        temp[1] = it[2];
        adj[it[0]].push_back(temp);

        // v -> {u, w}
        temp[0] = it[0];
        temp[1] = it[2];
        adj[it[1]].push_back(temp);
    }

    Prims p;
    int result = p.prims_algorithm(V, adj);
    cout << "Minimum Cost: " << result << endl;
    
    return 0;
}