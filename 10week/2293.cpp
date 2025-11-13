#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> coin;
int cache[100'002];

int dp() { 

    cache[0]=1;
    for(int i=0; i<n; i++){//동전의 종류
        for(int j=coin[i]; j<=k; j++){
            cache[j] += cache[j-coin[i]];//현재 coin[i]를 최소 1개 쓴다고 가정할때 j-coin[i]를 만드는가지수를더하기
        }
    }
    
    return cache[k];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    coin.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());
    cout<<dp();
}