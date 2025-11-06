#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board;
int dx[8]={0,1,2,0,2,0,1,2};
int dy[8]={0,0,0,1,1,2,2,2};

void recursive(int y, int x, int n){
    if(n==3){
        for(int i=0; i<8; i++){
            board[y+dy[i]][x+dx[i]]='*';
        }
        board[y+1][x+1]=' ';
        return;
    }
    int next_n=n/3;
    recursive(y,x,next_n);//1
    recursive(y,x+next_n,next_n);//2
    recursive(y,x+2*next_n,next_n);//3
    recursive(y+next_n,x,next_n);//4
    for(int i=0; i<next_n; i++){
        for(int j=0; j<next_n; j++){
            board[y+next_n+i][x+next_n+j]=' ';
        }
    }
    recursive(y+next_n,x+2*next_n,next_n);//6
    recursive(y+2*next_n,x,next_n);//7
    recursive(y+2*next_n,x+next_n,next_n);//8
    recursive(y+2*next_n,x+2*next_n,next_n);//9
    
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n; // n=3^k

    board.resize(n, vector<char>(n));

    recursive(0,0, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}