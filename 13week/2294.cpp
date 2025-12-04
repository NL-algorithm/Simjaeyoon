#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> coin;
int cache[10002];
int INF = 1e9;

int solve(int K){
    if(K==0) return 0;
    if(K<0) return INF;


    int &ret=cache[K];
    if(ret!=-1) return ret;

    ret=INF;
    for(int i=0; i<coin.size(); i++){
        int next = solve(K-coin[i]);//K를 채우기위해 i번째 코인을 쓰는경우
        if(next!=INF){
            ret=min(ret, next+1);
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        bool find=false;//중복되는 코인제거
        for(auto j : coin){
            if(j==t){
                find=true;
            }
        }
        if(!find){
            coin.push_back(t);
        }
    }
    sort(coin.begin(),coin.end());
    memset(cache,-1, sizeof(cache));
    int res = solve(k);
    if(res!=INF){
        cout<<res;
    }
    else{
        cout<<-1;
    }

    return 0;
}