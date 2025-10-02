#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string s;
    cin >> n >> m >> s;

    string target = "IOI";
    for (int i = 0; i < n - 1; i++) {
        target += "OI";
    }

    size_t start = 0;
    size_t end = s.find(target);
    int cnt = 0;
    //IOIOIOIIOOI
    while (end != string::npos) {
        cnt++;
        while(s.find("OI", end+target.length())==end+target.length()){
            cnt++;
            end+=2;
        }
        
        start = end+target.length();
        end = s.find(target, start);
    }
    cout << cnt;
}