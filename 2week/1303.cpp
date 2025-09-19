#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int y, int x, const vector<vector<char>> &board, vector<vector<bool>> &visit)
{
    int cnt = 1;

    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = true;

    while (!q.empty())
    {
        pair<int, int> start = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int yy = start.first + dy[i];
            int xx = start.second + dx[i];
            if (yy < 0 || xx < 0 || yy >= m || xx >= n)
                continue;
            else
            {
                if (!visit[yy][xx])
                {
                    if (board[start.first][start.second] == board[yy][xx])
                    {
                        q.push({yy, xx});
                        visit[yy][xx] = true;
                        cnt++;
                    }
                }
            }
        }
    }

    return cnt * cnt;
}

int main()
{
    FastIO;
    cin >> n >> m; // 가로, 세로

    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            board[i][j] = s[j];
        }
    }

    int w_sum = 0;
    int b_sum = 0;
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {

                if (board[i][j] == 'W')
                { // 우리편이면
                    w_sum += bfs(i, j, board, visit);
                }
                else
                { // 적팀이면
                    b_sum += bfs(i, j, board, visit);
                }
            }
        }
    }

    cout << w_sum << " " << b_sum;
}