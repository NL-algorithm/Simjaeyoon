#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> board;
int max_safe = 0;

// 바이러스의 이동
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void virus(vector<vector<int>> new_board) { // 벽3개선택한맵
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (new_board[i][j] == 2) { // 바이러스이면
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) { // 바이러스가 다 퍼질때까지
        pair<int, int> virus = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) { // 4방향으로 퍼지기
            int next_x = virus.second + dx[i];
            int next_y = virus.first + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N) continue; // 구역을 벗어나면

            if (new_board[next_y][next_x] == 0) { // 감염시킬수있으면
                new_board[next_y][next_x] = 2;
                q.push({next_y, next_x});
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (new_board[i][j] == 0) { // 안전 영역 세기
                cnt++;
            }
        }
    }
    max_safe=max(max_safe,cnt);
    return;
}

void chooseWall3(int cnt, int y, int x) {
    if (cnt == 3) {
        virus(board);
        return;
    }

    for (int i = y; i < N; i++) {
        int j_start = (i==y)? x: 0;//처음에만 x부터 시작이지 그다음줄탐색은 0부터해야하니
        for (int j = j_start; j < M; j++) {
            if (board[i][j] == 0) { // 벽을 세울수 있으면
                board[i][j] = 1;
                int next_x = j + 1;
                int next_y = i;
                if (next_x >= M) {
                    next_x = 0;
                    next_y += 1;
                }
                chooseWall3(cnt + 1, next_y, next_x); // 벽하나 선택
                board[i][j] = 0;                      // 선택 취소
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    board.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    chooseWall3(0, 0, 0);

    cout << max_safe;
    return 0;
}