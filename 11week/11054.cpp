#include <bits/stdc++.h>
using namespace std;

int N;           // 1이상 1000이하
vector<int> arr; // 각 1이상 1000이하
int cache[1002][1002][2];

int dp(int n, int last, bool up) {
    if (n == N) {
        return 0;
    }
    int &ret = cache[n][last][up];
    if (ret != -1) {
        return ret;
    }

    ret = max(ret, dp(n + 1, last, up)); // n포함 안시키기

    if (up) { // 증가중이면
        if (last < arr[n]) {
            ret = max(ret, dp(n + 1, arr[n], up) + 1); // n포함시키기
        }

        // 감소시작하기
        if (last > arr[n]) {
            ret = max(ret, dp(n + 1, arr[n], !up) + 1);
        }
    } else { // 감소중이면
        if (last > arr[n]) {
            ret = max(ret, dp(n + 1, arr[n], up) + 1); // 포함시키기
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    arr.resize(N); // 크기N으로
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));
    int res = max(dp(0, 0, true), dp(0, 1001, false));
    cout << res;
}