#include <bits/stdc++.h>
using namespace std;

class Tree {
public:
    int n;
    vector<vector<pair<int, int>>> adj;
    vector<int> d;

    Tree(int nodes) {
        n = nodes;
        adj.resize(n + 1);
        d.resize(n + 1, 0);
    }

    void addEdge(int parent, int child, int weight) {
        adj[parent].push_back({child, weight});
    }

    void TVS(int T, int parent, int delta) {
        d[T] = 0;
        
       
        for (auto &[child, weight] : adj[T]) {
            TVS(child, T, delta);
            d[T] = max(d[T], d[child] + weight);
        }

        if (parent != -1 && (d[T] + getWeight(parent, T) > delta)) {
            cout << "Split node: " << T << endl;
            d[T] = 0; // Reset d[T] after split
        }
    }

    int getWeight(int parent, int child) {
        for (auto &[v, w] : adj[parent]) {
            if (v == child) return w;
        }
        return 0;
    }
};

int main() {
    int n = 7, delta = 10;
    Tree tree(n);

    // Example tree structure
    tree.addEdge(1, 2, 5);
    tree.addEdge(1, 3, 4);
    tree.addEdge(2, 4, 3);
    tree.addEdge(2, 5, 2);
    tree.addEdge(3, 6, 6);
    tree.addEdge(3, 7, 1);

    cout << "Splitting nodes:\n";
    tree.TVS(1, -1, delta);

    return 0;
}
