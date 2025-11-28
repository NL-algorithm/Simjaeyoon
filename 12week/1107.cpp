#include <bits/stdc++.h>
using namespace std;

int N, M;                       // N:찾고자하는 채널
vector<bool> broken(10, false); // 0~9번까지 있음
int now = 100;                  // 현재 채널 번호

int check(int n) { // 채널 n을 누를수있는지 확인
    if (n == 0) {
        return broken[0] ? 0 : 1; // 0을 누를수있으면 true, 없으면 false
    }

    int len = 0;
    while (n > 0) {
        if (broken[n % 10]) { // 마지막자리 숫자가 고장나서 누를수없으면
            return 0;         // false
        }
        n /= 10;
        len++; // 한자리 누를수있음
    }
    return len; // 전부다 누를수있으면
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) { // 고장난 번호 입력
        int b;
        cin >> b;
        broken[b] = true;
    }

    int min_cnt = abs(N - 100);

    for (int i = 0; i <= 1000000; i++) {
        int len = check(i);
        if (len > 0) { // 누를수있었으면
            int cur_cnt = len + abs(N - i);
            min_cnt = min(min_cnt, cur_cnt);
        }
    }
    cout << min_cnt;
}