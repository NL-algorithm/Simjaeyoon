#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
using namespace std;

ll cache[101][10]; // 남은 자릿수, 앞 숫자
const ll k = 1'000'000'000;
ll n;

ll digit(ll nn, ll m)
{
    if(nn==0) return 1;
    if (nn == 1){//남은 자릿수가 1이면
        if(m==9||m==0)return 1;
        else return 2;
    }
    
    if (cache[nn][m] != 0)
    { // 이미 구해놨으면
        return cache[nn][m];
    }

    if(m==9){
        cache[nn][m]=digit(nn-1,8)%k;
    }
    else if(m==0){
        cache[nn][m]=digit(nn-1,1)%k;
    }
    else{
        cache[nn][m] = (digit(nn-1, m-1)%k+digit(nn-1, m+1)%k)%k;
    }

    return cache[nn][m]%k;
}

int main()
{

    cin >> n;

    ll result = 0;

    for (ll i = 1; i <= 9; i++)//맨앞자리 정하기
    {
        result =(result%k +digit(n-1,i)%k)%k;
    }

    cout << result;
}
