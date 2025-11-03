#include <bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<int>> board;
bool visited[26];

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int max_cnt=0;

void dfs(int y, int x, int cnt){
    
    if(cnt>max_cnt){
        max_cnt=cnt;
    }
        
    for(int k=0; k<4; k++){
        int yy=y+dy[k];
        int xx=x+dx[k];

        if(yy<=0||xx<=0||yy>r||xx>c){
            continue;
        }
        if(visited[board[yy][xx]]){//방문했었으면
            continue;
        }

        visited[board[yy][xx]]=true;
        dfs(yy,xx,cnt+1);
        visited[board[yy][xx]]=false;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>r>>c;

    board.resize(r+1,vector<int>(c+1));
    for(int i=1; i<=r; i++){
        string s;
        cin>>s;
        for(int j=1; j<=c; j++){
            board[i][j]=s[j-1]-'A';
        }
    }

    visited[board[1][1]]=true;
    dfs(1,1,1);
    cout<<max_cnt;
}