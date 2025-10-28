#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> house;   // 집 좌표
vector<pair<int, int>> chicken; // 치킨집 좌표
vector<vector<int>> dist;       // i번째 집에서 j번째 치킨집까지의 거리 dist[i][j]

vector<int> select_chicken_idx;
int total_min_dist = INT32_MAX;

void cal_dist() { // m개 골랏을때 도시의 치킨거리
    int cur_city_dist = 0;
    // i번째 집에서 j번째들중 치킨집 최소거리
    for (int i = 0; i < house.size(); i++) {
        int min_dist = INT32_MAX;
        for (auto j : select_chicken_idx) {
            min_dist = min(min_dist, dist[i][j]);
        }
        cur_city_dist += min_dist;
    }
    total_min_dist = min(total_min_dist, cur_city_dist);
    return;
}

void findCombination(int start, int m) {
    if (select_chicken_idx.size() == m) { // m개의 골랐으면
        cal_dist();
        return;
    }
    for (int i = start; i < chicken.size(); i++) {
        select_chicken_idx.push_back(i);
        findCombination(i + 1, m);
        select_chicken_idx.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                house.push_back({i, j});
            } else if (board[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    // 집에서 치킨집까지 거리 계산
    dist.resize(house.size(), vector<int>(chicken.size()));
    for (int i = 0; i < house.size(); i++) {
        for (int j = 0; j < chicken.size(); j++) {
            dist[i][j] = (abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
        }
    }

    findCombination(0, m); // 0번 치킨집부터 m개 고르는 조합
    cout << total_min_dist;
    return 0;
}