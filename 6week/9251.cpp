#include <bits/stdc++.h>
using namespace std;

int cache[1002][1002]; // s1에서 i번째까지문자열, s2,에서 j번째까지 공통문자열의 최대길이

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cache[i][j] = cache[i - 1][j - 1] + 1;
            } else {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
        }
    }
    cout << cache[n][m];
}