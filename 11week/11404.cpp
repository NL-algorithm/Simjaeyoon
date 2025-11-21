#include <bits/stdc++.h>
using namespace std;

const int INF = 2000000000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> bus(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int start, arrive, cost;
        cin >> start >> arrive >> cost;
        bus[start][arrive] = min(cost, bus[start][arrive]);
    }
    for (int i = 1; i <= n; i++) {
        bus[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {         // k번째 도시를 경유해서
        for (int i = 1; i <= n; i++) {     // i번째 도시에서
            for (int j = 1; j <= n; j++) { // j번째 도시로
                if (bus[i][k] != INF && bus[k][j] != INF) {
                    bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]); // 이전까지 최단경로, k를 거쳐가는거 비교
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (bus[i][j] == INF) {
                cout << 0 << " ";
            } else {
                cout << bus[i][j] << " ";
            }
        }
        cout << "\n";
    }
}