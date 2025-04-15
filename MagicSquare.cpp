#include <iostream>
#include <vector>
using namespace std;

// Function to generate an odd-sized magic square
void generateMagicSquare(int n) {
    if (n % 2 == 0) {
        cout << "Magic square is only implemented for odd numbers." << endl;
        return;
    }

    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int num = 1;
    int i = 0, j = n / 2;

    while (num <= n * n) {
        magicSquare[i][j] = num;
        num++;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (magicSquare[newi][newj]) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }

    // Print the magic square
    cout << "Magic Square of size " << n << ":\n";
    for (const auto& row : magicSquare) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }

    // Display the magic constant
    int magicConstant = n * (n * n + 1) / 2;
    cout << "Magic Constant: " << magicConstant << endl;
}

int main() {
    int n;
    cout << "Enter an odd number for the size of Magic Square: ";
    cin >> n;

    generateMagicSquare(n);
    return 0;
}
