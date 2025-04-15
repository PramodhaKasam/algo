#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Function to calculate retrieval time for a single tape
int singleTapeRetrievalTime(vector<int> lengths) {
    sort(lengths.begin(), lengths.end()); // Greedy: shortest first
    int totalTime = 0, cumulative = 0;

    for (int len : lengths) {
        cumulative += len;
        totalTime += cumulative;
    }

    return totalTime;
}

// Function to calculate retrieval time for multiple tapes
int multiTapeRetrievalTime(vector<int> lengths, int tapeCount) {
    sort(lengths.begin(), lengths.end()); // Greedy: shortest programs first

    // Min-heap to keep track of tape retrieval times
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> tapes;

    // Initialize tapes with zero retrieval time
    for (int i = 0; i < tapeCount; ++i) {
        tapes.push({0, {}});
    }

    for (int len : lengths) {
        auto [currentTime, tape] = tapes.top(); tapes.pop();
        tape.push_back(len);
        currentTime += len;
        tapes.push({currentTime, tape});
    }

    // Compute total retrieval time across all tapes
    int totalRetrieval = 0;
    while (!tapes.empty()) {
        auto [_, tape] = tapes.top(); tapes.pop();
        int cumulative = 0;
        for (int len : tape) {
            cumulative += len;
            totalRetrieval += cumulative;
        }
    }

    return totalRetrieval;
}

int main() {
    vector<int> programLengths = {10, 20, 30, 5, 15}; // Example program sizes
    int tapeCount = 2;

    cout << "Single Tape Total Retrieval Time: " << singleTapeRetrievalTime(programLengths) << endl;
    cout << "Multi-Tape (" << tapeCount << " tapes) Total Retrieval Time: " << multiTapeRetrievalTime(programLengths, tapeCount) << endl;

    return 0;
}
