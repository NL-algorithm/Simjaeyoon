#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;
int cache[1002][1002];//i번째 , 마지막

int dp(int n, int last){
    if(n==N){
        return 0;
    }

    int &ret = cache[n][last];
    if(ret!=-1)return ret;

    if(arr[n]<last){
        ret=max(ret, dp(n+1,arr[n])+1);//n번째를 포함하는경우
    }
    ret=max(ret,dp(n+1,last));//n번째를 포함안하는경우
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    arr.resize(N);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    memset(cache,-1,sizeof(cache));
    cout<<dp(0,1001);
}