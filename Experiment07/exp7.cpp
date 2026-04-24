#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
    // Step 1: Build adjacency list
    vector<vector<pair<int, int>>> adj(n);
    for (auto &flight : flights) {
        int u = flight[0];
        int v = flight[1];
        int w = flight[2];
        adj[u].push_back({v, w});
    }

    // Min heap → (cost, node, stops)
    priority_queue<tuple<int, int, int>, 
                   vector<tuple<int, int, int>>, 
                   greater<tuple<int, int, int>>> pq;

    pq.push({0, src, 0});

    while (!pq.empty()) {
        auto [cost, node, stops] = pq.top();
        pq.pop();

        // If destination reached
        if (node == dst) return cost;

        // If stops exceed k, skip
        if (stops > k) continue;

        for (auto &neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            pq.push({cost + weight, nextNode, stops + 1});
        }
    }

    return -1;
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };

    int src = 0, dst = 3, k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k);

    return 0;
}