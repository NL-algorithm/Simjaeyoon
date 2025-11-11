#include <bits/stdc++.h>
using namespace std;

int L, C; // L:암호의 길이, C:사용하는 문자의 수
vector<char> ch;

string pw;
char c[5] = {'a', 'e', 'i', 'o', 'u'};

set<string> unique_password;

bool check(const string &password) {
    int cnt1 = 0; // 모음 한개 체크 a,e,i,o,u
    for (int i = 0; i < password.length(); i++) {
        for (int j = 0; j < 5; j++) {
            if (password[i] == c[j]) { // 모음이면
                cnt1++;
            }
        }
    }
    if (cnt1 >= 1 && password.length() - cnt1 >= 2) {
        return true;
    }
    return false;
}

// 암호는 최소한개의 모음, 최소 두개의 자음으로 구성, 오름차순
void make_password(string &password, int i) {
    if (password.length() == L && check(password)) {
        unique_password.insert(password);
        return;
    }

    for (int j = i; j < ch.size(); j++) {
        password += ch[j];              // j번째 문자 선택
        make_password(password, j + 1); // j+1번째 이후 문자들로
        password.pop_back();            // j번째 문자 선택 취소
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;

    ch.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> ch[i];
    }
    sort(ch.begin(), ch.end()); // 오름차순으로 정렬

    make_password(pw, 0);

    for (const string &pass : unique_password) {
        cout << pass << "\n";
    }
}