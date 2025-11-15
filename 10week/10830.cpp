#include <bits/stdc++.h>
using namespace std;

long long N, B;
vector<vector<long long>> mat;

void printMat(const vector<vector<long long>> &mat) {
    for (long long i = 0; i < N; i++) {
        for (long long j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

vector<vector<long long>> multiple(vector<vector<long long>> &t1, vector<vector<long long>> &t2) {
    vector<vector<long long>> res(N, vector<long long>(N));
    for (long long i = 0; i < N; i++) {
        for (long long j = 0; j < N; j++) {
            long long sum = 0;
            for (long long k = 0; k < N; k++) {
                sum = (sum % 1000 + (t1[i][k] * t2[k][j]) % 1000) % 1000;
            }
            res[i][j] = sum % 1000;
        }
    }
    return res;
}

vector<vector<long long>> multiplication(vector<vector<long long>> &mat, long long b) {
    if (b == 1) {
        return mat;
    }

    if (b % 2 == 1) { // b가 홀수라면
        vector<vector<long long>> tmp = multiplication(mat, b - 1);
        return multiple(mat, tmp);
    } else { // b가 짝수일때
        vector<vector<long long>> tmp = multiplication(mat, b / 2);
        return multiple(tmp, tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> B;
    mat.resize(N, vector<long long>(N));
    for (long long i = 0; i < N; i++) {
        for (long long j = 0; j < N; j++) {
            cin >> mat[i][j];
            mat[i][j]%=1000;
        }
    }
    printMat(multiplication(mat, B));
}