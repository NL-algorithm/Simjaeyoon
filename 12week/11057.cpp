#include <bits/stdc++.h>
using namespace std;

int N;
int cache[1002][11];

int dp(int idx, int last) {//마지막숫자가last인 idx자리 수
    if(idx==1){//자리수가 1이면 개수는 1개
        return 1;
    }

    int &ret = cache[idx][last];
    if (ret != -1) return ret;

    ret=0;
    for(int i=0; i<=last; i++){
        ret=(ret+dp(idx-1,i))%10007;
        //idx-1인자리수에서 마지막이 last보다 작거나같다
    }

    return ret;
}

int main() {
    cin >> N;
    memset(cache, -1, sizeof(cache));
    
    int res=0;
    for(int i=0; i<=9; i++){
        res=(res+dp(N,i))%10007;//마지막숫자가 i인 N자리수
    }
    cout<<res;
}