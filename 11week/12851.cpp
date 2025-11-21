#include <bits/stdc++.h>
using namespace std;

int N, K;
int time_arr[100'002];  // 각 위치까지의 최단 시간 기록
int count_arr[100'002]; // 각 위치까지의 최단시간으로 가는 방법의 수

void bfs(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (time_arr[now] > time_arr[K] && time_arr[K] != 0) { // K가 0이 아닐때 즉 K를 찾았을때 찾은시간보다 넘으면
            return;
        }

        int x[3] = {now - 1,
                    now + 1,
                    2 * now};

        for (int i = 0; i < 3; i++) {
            int next = x[i];
            if (next < 0 || next > 100'000) continue;

            if (time_arr[next] == 0) {              // 방문흔적이 없으면 첫방문이면
                time_arr[next] = time_arr[now] + 1; // 지금까지 time에 +1
                count_arr[next] = count_arr[now];   // 지금까지 가짓수 그대로
                q.push(next);
            } else if (time_arr[next] == time_arr[now] + 1) { // 같은시간대 재방문 즉 다른방법으로
                count_arr[next] += count_arr[now];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    if (N == K) {
        cout << 0 << "\n"
             << 1;
        return 0;
    }

    time_arr[N] = 0;
    count_arr[N] = 1;
    bfs(N);
    cout << time_arr[K] << "\n"
         << count_arr[K];
}