#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, int>;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, e; // 정점, 간선
    cin >> n >> e;
    vector<vector<pii>> edges(n + 1); // 거리, 도착점

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back({w, b});
        edges[b].push_back({w, a});
    }
    int a, b;
    cin >> a >> b;

    if(e==0){
        cout<<-1;
        return 0;
    }

    // 1번점에서부터의 최소거리
    priority_queue<pii, vector<pii>, greater<pii>> pq1; // 방문할 노드, 거리오름차순정렬
    long long one_a = INF, one_b = INF;

    vector<long long> dist1(n + 1, INF);
    dist1[1] = 0;
    pq1.push({0, 1});
    while (!pq1.empty()) {
        int cur_dist = pq1.top().first;
        int cur_node = pq1.top().second;
        pq1.pop();
        if (cur_node == a) {
            one_a = dist1[a];
        }
        if (cur_node == b) {
            one_b = dist1[b];
        }

        for (auto edge : edges[cur_node]) {
            int new_dist = cur_dist + edge.first;
            if (new_dist < dist1[edge.second]) { // 더 짧은 경로면
                dist1[edge.second] = new_dist;
                pq1.push({new_dist, edge.second});
            }
        }
    }

    // a에서부터 다익스트라
    priority_queue<pii, vector<pii>, greater<pii>> pqa; // 방문할 노드, 거리오름차순정렬
    long long atob = INF;
    long long aton = INF;

    vector<long long> dista(n + 1, INF);
    dista[a] = 0;
    pqa.push({0, a});
    while (!pqa.empty()) {
        int cur_dist = pqa.top().first;
        int cur_node = pqa.top().second;

        if (cur_node == b) {
            atob = dista[b];
        }
        if (cur_node == n) {
            aton = dista[n];
        }

        pqa.pop();
        for (auto edge : edges[cur_node]) {
            int new_dist = cur_dist + edge.first;
            if (new_dist < dista[edge.second]) { // 더 짧은 경로면
                dista[edge.second] = new_dist;
                pqa.push({new_dist, edge.second});
            }
        }
    }

    // b에서부터
    priority_queue<pii, vector<pii>, greater<pii>> pqb; // 방문할 노드, 거리오름차순정렬
    long long btoa = INF;
    long long bton = INF;

    vector<long long> distb(n + 1, INF);
    distb[b] = 0;
    pqb.push({0, b});
    while (!pqb.empty()) {
        int cur_dist = pqb.top().first;
        int cur_node = pqb.top().second;

        if (cur_node == a) {
            btoa = distb[a];
        }
        if (cur_node == n) {
            bton = distb[n];
        }

        pqb.pop();
        for (auto edge : edges[cur_node]) {
            int new_dist = cur_dist + edge.first;
            if (new_dist < distb[edge.second]) { // 더 짧은 경로면
                distb[edge.second] = new_dist;
                pqb.push({new_dist, edge.second});
            }
        }
    }

    // 1-a-b-n
    long long distab = one_a + atob + bton;
    // 1-b-a-n
    long long distba = one_b + btoa + aton;

    long long mindist = min(distab, distba);
    if (mindist < 0 || mindist >= INF) {
        mindist = -1;
    }
    cout << mindist;
}