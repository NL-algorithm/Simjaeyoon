#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,int>>> adj;
bool visited[10002];
int maxDist=0;
int fartestNode =1;

void dfs(int node, int cur_weight){//현재노드, 시작점부터 현재까지 누적 가중치
    visited[node] = true;

    if(cur_weight>maxDist){
        maxDist=cur_weight;
        fartestNode=node;
    }

    for(auto& edge : adj[node]){
        int nextNode= edge.first;
        int weight= edge.second;

        if(!visited[nextNode]){
            dfs(nextNode, cur_weight+weight);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    
    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int parent, son, weight;
        cin>>parent>>son>>weight;
        adj[parent].push_back({son, weight});
        adj[son].push_back({parent, weight});
    }

    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(1,0);

    memset(visited, false, sizeof(visited));
    maxDist=0;
    dfs(fartestNode,0);

    cout<<maxDist;

}