#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1);

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : adj[current]) {           // 연결된 모든점 탐색
            if (parent[next] == 0 && next != 1) { // 아직 부모설정이 안됬으면
                parent[next] = current;
                q.push(next);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }
}