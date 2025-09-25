#include <bits/stdc++.h>
using namespace std;

bool check_sq(const vector<vector<int>> &board,int side, int y, int x){//한변의 길이, 왼쪽위의 좌표
    if(board[y][x]==board[y][x+side-1]&&board[y][x]==board[y+side-1][x]&&board[y][x]==board[y+side-1][x+side-1]){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> board(n,vector<int>(m));
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            board[i][j]=s[j];
        }
    }
    int small = (n<m?n:m);

    for(int i=small; i>=1; i--){//한변의 크기를 줄여간다.
        for(int y = 0; y+i-1<n; y++){
            for(int x =0; x+i-1<m; x++){
                if(check_sq(board, i, y,x)){
                    cout<<i*i;
                    return 0;
                }
            }
        }
    }
}