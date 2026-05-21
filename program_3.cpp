#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

struct DisjointSets {
    vector<int> parent, rank;
    DisjointSets(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j]) rank[root_i]++;
            return true;
        }
        return false;
    }
};

int main() {
    int V;
    if (!(cin >> V)) return 0;
    vector<Edge> edges;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int w;
            cin >> w;
            if (w != 0 && i < j) {
                edges.push_back({i, j, w});
            }
        }
    }

    sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    int totalWeight = 0;
    int edgesCount = 0;

    for (const auto& edge : edges) {
        if (ds.unite(edge.u, edge.v)) {
            totalWeight += edge.weight;
            edgesCount++;
            if (edgesCount == V - 1) break;
        }
    }

    cout << "Maximum Spanning Weight: " << totalWeight << endl;
    return 0;
}