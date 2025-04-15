#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper to map parent pointers
void mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front(); q.pop();
        if (current->left) {
            parentMap[current->left] = current;
            q.push(current->left);
        }
        if (current->right) {
            parentMap[current->right] = current;
            q.push(current->right);
        }
    }
}

// Helper to find node by value
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

// BFS to find shortest path between source and destination
vector<int> shortestPath(TreeNode* root, int sourceVal, int destVal) {
    if (!root) return {};

    unordered_map<TreeNode*, TreeNode*> parentMap;
    mapParents(root, parentMap);

    TreeNode* source = findNode(root, sourceVal);
    TreeNode* dest = findNode(root, destVal);

    if (!source || !dest) {
        cout << "Source or Destination node not found!" << endl;
        return {};
    }

    unordered_map<TreeNode*, bool> visited;
    unordered_map<TreeNode*, TreeNode*> prev;

    queue<TreeNode*> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        TreeNode* current = q.front(); q.pop();

        if (current == dest) break;

        vector<TreeNode*> neighbors = {current->left, current->right, parentMap[current]};
        for (TreeNode* neighbor : neighbors) {
            if (neighbor && !visited[neighbor]) {
                visited[neighbor] = true;
                prev[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    // Reconstruct path
    vector<int> path;
    for (TreeNode* at = dest; at != nullptr; at = prev[at]) {
        path.push_back(at->val);
        if (at == source) break;
    }
    reverse(path.begin(), path.end());
    return path;
}

// Example binary tree:
//         1
//        / \
//       2   3
//      / \   \
//     4   5   6

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    int source = 4, destination = 6;

    vector<int> path = shortestPath(root, source, destination);

    cout << "Shortest path from " << source << " to " << destination << ": ";
    for (int val : path) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
