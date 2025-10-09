#include <bits/stdc++.h>
using namespace std;

long long a,b;

void bfs(long long n){
    queue<long long> q;
    q.push(n);
    long long cnt=1;
    while(!q.empty()){
        long long size = q.size();
        for(long long i=0; i<size; i++){
            long long cur = q.front();
            q.pop();
            if(cur==b){
                cout<<cnt;
                return;
            }
            else if(cur>b){
                continue;
            }

            long long n1 = cur*2;
            long long n2 = cur*10+1;
            q.push(n1);
            q.push(n2);
        }
        cnt++;
    }
    cout<<-1;
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>a>>b;

    bfs(a);
}