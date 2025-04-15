#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Function to find the shortest path in a multi-stage graph
int shortestPath(vector<vector<pair<int, int>>>& graph, int N, int source, int destination) {
    vector<int> dist(N, INF);
    dist[destination] = 0;

    // Traverse nodes from second last to the source
    for (int i = N - 2; i >= 0; --i) {
        for (auto& edge : graph[i]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[v] != INF)
                dist[i] = min(dist[i], weight + dist[v]);
        }
    }

    return dist[source];
}

int main() {
    int N = 8; // Total number of vertices (0 to 7)
    vector<vector<pair<int, int>>> graph(N);

    // Define edges in the form graph[u].push_back({v, weight});
    graph[0].push_back({1, 1});
    graph[0].push_back({2, 2});
    graph[1].push_back({3, 3});
    graph[1].push_back({4, 4});
    graph[2].push_back({4, 2});
    graph[3].push_back({5, 6});
    graph[4].push_back({5, 1});
    graph[5].push_back({6, 3});
    graph[6].push_back({7, 1});

    int source = 0;
    int destination = 7;

    int result = shortestPath(graph, N, source, destination);
    cout << "Shortest path cost from source to destination: " << result << endl;

    return 0;
}
