#include <bits/stdc++.h>
using namespace std;

int n, m;                         // 사람수, 파티수
int true_num;                     // 진실을아는사람수
vector<bool> true_idx(51, false); // 아는 사람들 번호

bool compare(const vector<int> &a, const vector<int> &b) {
    return a.size() > b.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> true_num; // 총 n명, 파티의 수 m개, 처음에 진실을아는 사람의 수
    for (int i = 0; i < true_num; i++) {
        int a;
        cin >> a;
        true_idx[a] = true;
    }
    vector<vector<int>> party(m);
    for (int i = 0; i < m; i++) {
        int now_party_num;
        cin >> now_party_num;
        party[i].resize(now_party_num);
        for (int j = 0; j < now_party_num; j++) {
            cin >> party[i][j];
        }
    }
    sort(party.begin(), party.end(), compare);

    // 진실말한곳 다 진실
    vector<bool> party_true(m, false); // 진실파티
    for (int i = 0; i < m; i++) {
        if (party_true[i])
            continue;
        for (int j = 0; j < party[i].size(); j++) {
            if (true_idx[party[i][j]]) { // 진실을 알고있는사람이면
                for (int k = 0; k < party[i].size(); k++) {
                    true_idx[party[i][k]] = true;
                }
                party_true[i] = true;
                i = -1;
                break;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (!party_true[i]) {
            cnt++;
        }
    }
    cout << cnt;
}