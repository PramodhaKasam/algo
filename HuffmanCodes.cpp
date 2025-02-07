#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        this->data = d;
        this->freq = f;
        left = right = NULL;
    }
};

class Compare {
public:
    bool operator()(Node* left, Node* right) {
        return (left->freq > right->freq);
    }
};

void printCodes(Node* top, string str) {
    if (top == NULL) return;

    if (top->data != '$') {
        cout << top->data << " : " << str << endl;
    }

    printCodes(top->left, str + '0');
    printCodes(top->right, str + '1');
}

void huffmanCodes(vector<char> arr, vector<int> freq, int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new Node(arr[i], freq[i]));
    }

    while (pq.size() > 1) {
        Node *left, *right, *top;
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printCodes(pq.top(), "");
}

int main() {
    vector<char> arr = {'a', 'b', 'c', 'd', 'e'};
    vector<int> freq = {20, 12, 17, 35, 56};

    int n = arr.size();
    huffmanCodes(arr, freq, n);

    return 0;
}
