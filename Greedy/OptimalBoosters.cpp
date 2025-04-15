#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int to;
    int loss;
};

vector<vector<Edge>> tree;
int boosterCount = 0;
int lossLimit;

void dfs(int node, int parent, int accumulatedLoss) {
    if (accumulatedLoss > lossLimit) {
        // Place booster here
        boosterCount++;
        accumulatedLoss = 0; // Reset loss after booster
    }

    for (const Edge& edge : tree[node]) {
        if (edge.to != parent) {
            dfs(edge.to, node, accumulatedLoss + edge.loss);
        }
    }
}

int main() {
    int n, L;
    cout << "Enter number of nodes and loss tolerance level: ";
    cin >> n >> L;
    lossLimit = L;

    tree.resize(n);

    cout << "Enter " << n - 1 << " edges (format: u v loss):\n";
    for (int i = 0; i < n - 1; ++i) {
        int u, v, loss;
        cin >> u >> v >> loss;
        tree[u].push_back({v, loss});
        tree[v].push_back({u, loss});
    }

    // Start DFS from root node 0
    dfs(0, -1, 0);

    cout << "Minimum boosters needed: " << boosterCount << endl;
    return 0;
}
