#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>> &board, int idx, int i, int j){
    if(idx==1){
        cout<<board[i][j];
        return;
    }

    
    for(int n=0; n<idx; n++){
        for(int m=0; m<idx; m++){
            if(board[i][j]!=board[i+n][j+m]){
                int half = idx/2;
                cout<<"(";
                dfs(board, half, i,j); dfs(board, half, i, j+half);
                dfs(board, half, i+half, j); dfs(board, half, i+half, j+half);

                cout<<")";
                return;
            }
        }
    }
    cout<<board[i][j];
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n));
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            board[i][j] = s[j]-'0';
        }
    }

    dfs(board, n, 0,0);
    
}