#include <bits/stdc++.h>
using namespace std;

int n;
int dx[2] = {1,0};
int dy[2] = {0,1};
int cache[502][502][5];// 
string sss = "MOLA";

int dfs(int y, int x, const vector<vector<char>> &board, int s_len){//i,j에서 시작

    if(x>n||y>n||y<1||x<1) return 0;

    int &ret = cache[y][x][s_len];
    if(ret!=-1) return ret;//개선한 값이 있으면

    int next_s_len = s_len;
    int count=0;

    if(sss[s_len]==board[y][x]){
        next_s_len++;
        if(next_s_len==4){
            count++;
            next_s_len=0;
        }
    }
    else{
        if(board[y][x]=='M'){
            next_s_len=1;
        }
        else{
            next_s_len=0;
        }
    }
    
    
    int sub_path=0;
    for(int i=0; i<2; i++){//2가지 길
        int yy = y+dy[i];
        int xx = x+dx[i];
        sub_path = max(sub_path, dfs(yy,xx,board,next_s_len));
    }
    ret = count + sub_path;
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n;
    vector<vector<char>> board(n+1, vector<char>(n+1));
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            board[i][j+1]=s[j];
        }
    }

    memset(cache,-1 , sizeof(cache));
    string s;
    cout<<dfs(1,1, board, 0);

    return 0;
}