#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int T = 0; T < t; T++) {
        string p, s;
        int n;
        cin >> p >> n >> s;
        deque<int> dq;
        if (s.size() > 2) {
            string ss = s.substr(1, s.size() - 1);
            size_t start = 0;
            size_t end = ss.find(',');
            while (end != string::npos) {
                dq.push_back(stoi(ss.substr(start, end - start)));
                start = end + 1;
                end = ss.find(',', start);
            }
            dq.push_back(stoi(ss.substr(start)));
        }

        bool ok = true;
        bool front = true;
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                front = !front;
            } else {
                if (!dq.empty()) {
                    if (front) {
                        dq.pop_front();
                    } else {
                        dq.pop_back();
                    }
                } else {
                    cout << "error\n";
                    ok = false;
                    i = p.length();
                }
            }
        }
        if (!ok)
            continue;
        cout << "[";
        if (!dq.empty()) {
            if (front) {
                for (int i = 0; i < dq.size() - 1; i++) {
                    cout << dq[i] << ",";
                }
                cout << dq.back();
            } else {
                for (int i = dq.size() - 1; i > 0; i--) {
                    cout << dq[i] << ",";
                }
                cout << dq.front();
            }
        }

        cout << "]\n";
    }
}