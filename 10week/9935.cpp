#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char str[1'000'001];
    cin.getline(str, 1'000'001);
    char boom[37];
    cin.getline(boom, 37);

    int strSize = strlen(str);
    int boomSize = strlen(boom);
    vector<bool> arr(strSize, true);
    stack<pair<int, int>> st;
    int conti = 0; // 찾는idx
    bool find;
    for (int i = 0; i < strSize; i++) {
        find = false;
        if (str[i] == boom[0]) { // 시작
            conti = 1;
            st.push({conti, i});
            find = true;
        }
        if (str[i] == boom[conti]) {
            st.push({++conti, i});
            find = true;
        }
        if (!find) { // 이번에 같은게 없었으면
            conti = 0;
            while (!st.empty()) {
                st.pop();
            }
        }
        if (conti == boomSize) {
            for (int j = 0; j < boomSize; j++) {
                int now = st.top().second;
                arr[now] = false;
                st.pop();
            }
            if (!st.empty()) {
                conti = st.top().first;
            } else {
                conti = 0;
            }
        }
    }
    bool allFalse = true;
    for (int i = 0; i < strSize; i++) {
        if (arr[i]) {
            cout << str[i];
            allFalse = false;
        }
    }
    if (allFalse) {
        cout << "FRULA";
    }
}