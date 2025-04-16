#LRS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestRepeatedSubsequence(string str) {
    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Build the dp table (similar to LCS, but with i != j)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i - 1] == str[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    // Recover the LRS from the dp table
    string res = "";
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j - 1] + 1 && str[i - 1] == str[j - 1] && i != j) {
            res = str[i - 1] + res;
            i--; j--;
        } else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }

    return res;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string result = longestRepeatedSubsequence(str);
    cout << "Longest Repeated Subsequence: " << result << endl;

    return 0;
}
TC=SC= O(n^2)
