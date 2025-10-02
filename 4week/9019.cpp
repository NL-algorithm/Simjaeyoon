#include <bits/stdc++.h>
using namespace std;

int D(int n) {
    return 2 * n % 10000;
}
int S(int n) {
    if (n == 0)
        return 9999;
    return n - 1;
}
int L(int n) { // 1234  2341
    return (n % 1000) * 10 + (n / 1000);
}
int R(int n) {//1234 4123   123  312
    return (n % 10) * 1000 + (n / 10);
}

void bfs(int a, int b) {
    vector<bool> visit(10000, false);
    queue<pair<int, string>> q;
    q.push({a, ""});
    visit[a] = true;

    while (!q.empty()) {
        pair<int, string> start = q.front();
        q.pop();
        if (start.first == b) {
            cout << start.second << "\n";
            return;
        }
        int d = D(start.first);
        int s = S(start.first);
        int l = L(start.first);
        int r = R(start.first);
        if (!visit[d]) {
            q.push({d, start.second + "D"});
            visit[d] = true;
        }
        if (!visit[s]) {
            q.push({s, start.second + "S"});
            visit[s] = true;
        }
        if (!visit[l]) {
            q.push({l, start.second + "L"});
            visit[l] = true;
        }
        if (!visit[r]) {
            q.push({r, start.second + "R"});
            visit[r] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
    }
}