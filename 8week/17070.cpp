#include <bits/stdc++.h>
using namespace std;

int n;
enum Status { row, col, diagonal};
int cnt=0;
vector<vector<int>> board;

void dfs(int i, int j, Status status){//현재좌표, 현재 상태
    if(i==n&&j==n){
        cnt++;
        return;
    }
    
    //대각선으로는 다 가능
    if(board[i+1][j+1]==0&&board[i][j+1]==0&&board[i+1][j]==0){
        dfs(i+1,j+1, diagonal);
    }
    if(status==row){
        if(board[i][j+1]==0){
            dfs(i,j+1, row);
        }
    }
    if(status==col){
        if(board[i+1][j]==0){
            dfs(i+1, j, col);
        }
    }
    if(status==diagonal){
        if(board[i][j+1]==0){
            dfs(i,j+1, row);
        }
        if(board[i+1][j]==0){
            dfs(i+1, j, col);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n;
    board.resize(n+2, vector<int>(n+2,-1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>board[i][j];
        }
    }
    dfs(1,2, row);
    cout<<cnt;
}