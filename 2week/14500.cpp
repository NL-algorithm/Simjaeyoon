#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                      \
    cout.tie(0);
using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int max_sum = 0;

void dfs(int y, int x, int cnt, vector<vector<bool>> &visit, const vector<vector<int>> &board, int sum)
{
    if (cnt == 0)
    {
        max_sum = max(max_sum, sum);
        return;
    }
    visit[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (yy >= 0 && xx >= 0 && yy < n && xx < m)
        {
            if (!visit[yy][xx])
            {
                dfs(yy, xx, cnt - 1, visit, board, sum + board[yy][xx]);
            }
        }
    }
    visit[y][x] = false;
}

int main()
{
    FastIO;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    vector<vector<bool>> visit(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dfs(i, j, 3, visit, board, board[i][j]);
        }
    }

    // ㅗ 모양 예외 처리
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t = board[i][j]; // 가운데 점
            int del = INT_MAX;
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m)
                {
                    cnt++;
                    if (del > board[ny][nx])
                    {
                        del = board[ny][nx];
                    }
                    t += board[ny][nx];
                }
            }
            if (cnt == 4)
            {
                // 4개 모두 있을 때는 최소값 빼고 계산
                max_sum = max(max_sum, t - del);
            }
            else if (cnt == 3)
            {
                // 3개인 경우 
                max_sum = max(max_sum, t);
            }
            // 2개 이하인 경우는 무시
        }
    }

    cout << max_sum;
}
