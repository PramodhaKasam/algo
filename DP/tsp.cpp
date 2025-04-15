#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;
int n; // number of cities
vector<vector<int>> dist;
vector<vector<int>> dp;

// tsp(mask, pos): minimum cost to visit all cities in mask starting from pos
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        // all cities visited, return to start
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int minCost = INF;
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0) {
            // city not visited
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city);
            minCost = min(minCost, newCost);
        }
    }

    return dp[mask][pos] = minCost;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    dist.resize(n, vector<int>(n));
    dp.resize(1 << n, vector<int>(n, -1));

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];

    int result = tsp(1, 0); // starting from city 0 with only it visited
    cout << "Minimum cost of TSP tour: " << result << endl;

    return 0;
}
