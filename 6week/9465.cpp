#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        // 스티커 점수저장배열
        vector<vector<int>> sticker(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            cin >> sticker[0][i];
        }
        for (int i = 0; i < n; i++) {
            cin >> sticker[1][i];
        }

        // 스티커 점수의 최댓값 구하기
        int cache[2][100'102]; // 기억하기
        memset(cache, -1, sizeof(cache));
        cache[0][1] = sticker[0][0];
        cache[1][1] = sticker[1][0];
        if (n >= 2) {
            cache[0][2] = cache[1][1] + sticker[0][1];
            cache[1][2] = cache[0][1] + sticker[1][1];
            for (int i = 2; i <= n; i++) { // n번째 줄까지
                for (int j = 0; j < 2; j++) {
                    if (j == 0) { // 첫번째 행일때
                        cache[j][i] = max(cache[j + 1][i - 1], cache[j + 1][i - 2]) + sticker[j][i - 1];
                    } else { // 두번째 행일때
                        cache[j][i] = max(cache[j - 1][i - 1], cache[j - 1][i - 2]) + sticker[j][i - 1];
                    }
                }
            }
        }

        int max_sum = max({cache[0][n], cache[1][n], cache[0][n - 1], cache[1][n - 1]});
        cout << max_sum << "\n";
    }
}