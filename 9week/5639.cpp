#include <bits/stdc++.h>
using namespace std;

int arr[10'002];

void post_order(int start, int end) {
    if (start >= end) {
        return;
    }

    if (start == end - 1) {
        cout << arr[start] << "\n";
        return;
    }

    int idx = start + 1;
    while (idx < end) {
        if (arr[start] < arr[idx]) {
            break;
        }
        idx++;
    }
    post_order(start + 1, idx);
    post_order(idx, end);
    cout << arr[start] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, i = 0;
    while (cin >> a) {
        arr[i++] = a;
    }
    post_order(0, i);
}