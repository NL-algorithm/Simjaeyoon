#include <bits/stdc++.h>
using namespace std;

int dx[8] = {0,1,2,3,4,1,3,2};
int dy[8] = {0,0,0,0,0,-1,-1,-2};

void recursive(int y, int x, int size, vector<vector<char>> &board) {
    if (size == 3) {
        for (int i = 0; i < 8; i++) {
            board[y + dy[i]][x + dx[i]] = '*';
        }
        return;
    }
    int next_size = size / 2;
    recursive(y, x, next_size, board);
    recursive(y, x + size, next_size, board);
    recursive(y-next_size, x + size / 2, next_size, board);

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; // n = 3*2^k
    cin >> n;

    vector<vector<char>> board(n, vector<char>(2 * n - 1, ' '));

    recursive(n-1, 0, n, board);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}