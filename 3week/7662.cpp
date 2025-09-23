#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    for(int t=0; t<T; t++){
        int k;
        cin>>k;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minPQ;//값, 인덱스
        priority_queue<pair<int,int>> maxPQ;
        vector<bool> exist;
        int index=0;

        for(int i=0; i<k; i++){
            char op;
            int n;
            cin>>op>>n;

            if(op=='I'){//input
                minPQ.push({n, index});
                maxPQ.push({n,index});
                exist.push_back(true);
                index++;
            }
            else{//delete
                if(n==1&&!maxPQ.empty()){
                    exist[maxPQ.top().second]=false;//exist의 index번째를 false
                    maxPQ.pop();
                    while(!maxPQ.empty()&&!exist[maxPQ.top().second]){//그다음 maxPQ의 값이 존재하지 않는거면 팝
                        maxPQ.pop();
                    }
                    while(!minPQ.empty()&&!exist[minPQ.top().second]){
                        minPQ.pop();
                    }
                }
                if(n==-1&&!minPQ.empty()){
                    exist[minPQ.top().second]=false;//exist의 index번째를 false
                    minPQ.pop();
                    while(!minPQ.empty()&&!exist[minPQ.top().second]){
                        minPQ.pop();
                    }
                    while(!maxPQ.empty()&&!exist[maxPQ.top().second]){//그다음 maxPQ의 값이 존재하지 않는거면 팝
                        maxPQ.pop();
                    }
                }
            }
        }
        if(!maxPQ.empty()&&!minPQ.empty()){
            cout<<maxPQ.top().first<<" "<<minPQ.top().first;
        }
        else{
            cout<<"EMPTY";
        }
        cout<<"\n";
    }
}