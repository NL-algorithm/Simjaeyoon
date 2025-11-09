#include <bits/stdc++.h>
using namespace std;

int n; // 1~14
int ans=0;
int col[15];//i번째 행에서의 퀸의 열위치

bool is_possible(int now){//현재 행이 가능한지 확인
    for(int i=0; i<now; i++){
        if(col[i]==col[now]||abs(col[now]-col[i])==now-i){
            return false;
        }
    }
    return true;
}

void nqeen(int row){//현재 행
    if(row==n){
        ans++;
        return;
    }
    
    for(int i=0; i<n; i++){
        col[row]=i;//현재 행에 대해 1~14까지 대입
        if(is_possible(row)){//만든 행이 가능한지 확인
            nqeen(row+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    nqeen(0);
    cout<<ans;
}