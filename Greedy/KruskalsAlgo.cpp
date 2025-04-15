#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (Union-Find) with Path Compression and Union by Rank
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false;

        if(rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    DSU dsu(V);
    vector<Edge> mst;
    int totalWeight = 0;

    for(const auto& edge : edges) {
        if(dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for(const auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int V = 6; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 5},
        {2, 4, 11},
        {3, 4, 2},
        {3, 5, 1},
        {4, 5, 7}
    };

    kruskalMST(V, edges);

    return 0;
}
