#include <bits/stdc++.h>
using namespace std;

const int N = 4; // 4x4 puzzle

// Directions for moving the blank tile (up, down, left, right)
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Goal state for reference
vector<vector<int>> goal = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
};

struct Puzzle {
    vector<vector<int>> mat;
    int x, y; // Position of the blank tile (0)
    int g, h; // g = cost so far, h = heuristic
    string path; // path of moves

    Puzzle(vector<vector<int>> m, int x_, int y_, int g_, string path_)
        : mat(m), x(x_), y(y_), g(g_), path(path_) {
        h = calculateHeuristic();
    }

    // Manhattan Distance
    int calculateHeuristic() {
        int dist = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (mat[i][j] != 0) {
                    int val = mat[i][j] - 1;
                    int targetX = val / N;
                    int targetY = val % N;
                    dist += abs(i - targetX) + abs(j - targetY);
                }
        return dist;
    }

    int f() const {
        return g + h;
    }

    // For priority queue: smaller f() comes first
    bool operator<(const Puzzle& other) const {
        return f() > other.f(); // reverse for min-heap
    }

    // For visited state checking
    string serialize() const {
        string s;
        for (auto& row : mat)
            for (int num : row)
                s += to_string(num) + ",";
        return s;
    }
};

// Try solving using A*
bool solve15Puzzle(vector<vector<int>> start) {
    int startX, startY;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (start[i][j] == 0)
                startX = i, startY = j;

    priority_queue<Puzzle> pq;
    set<string> visited;

    pq.push(Puzzle(start, startX, startY, 0, ""));
    visited.insert(Puzzle(start, startX, startY, 0, "").serialize());

    while (!pq.empty()) {
        Puzzle curr = pq.top();
        pq.pop();

        if (curr.mat == goal) {
            cout << "Puzzle Solved in " << curr.g << " moves!\n";
            cout << "Move sequence: " << curr.path << endl;
            return true;
        }

        for (int d = 0; d < 4; ++d) {
            int newX = curr.x + dx[d];
            int newY = curr.y + dy[d];

            if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
                vector<vector<int>> newMat = curr.mat;
                swap(newMat[curr.x][curr.y], newMat[newX][newY]);
                string newPath = curr.path + "URDL"[d];
                Puzzle next(newMat, newX, newY, curr.g + 1, newPath);

                string key = next.serialize();
                if (!visited.count(key)) {
                    visited.insert(key);
                    pq.push(next);
                }
            }
        }
    }

    cout << "Puzzle is unsolvable!\n";
    return false;
}

int main() {
    vector<vector<int>> start(N, vector<int>(N));
    cout << "Enter initial 4x4 puzzle configuration (use 0 for blank):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> start[i][j];

    solve15Puzzle(start);
    return 0;
}
