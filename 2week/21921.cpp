#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                      \
    cout.tie(0);
using namespace std;

int main(){
    FastIO;
    int n,x;
    cin>>n>>x;
    vector<int> visit(n+1);
    for(int i=1; i<=n; i++){
        cin>>visit[i];//i번째 날 방문객수
    }

    vector<int> p_sum(n+1,0);//누적합 prefix_sum
    for(int i=1; i<=n; i++){
        p_sum[i] = p_sum[i-1]+visit[i];
    }

    int x_window_max=0;
    int cnt=0;
    for(int i=0; i<=n-x; i++){
        int tmp = p_sum[i+x]-p_sum[i];
        if(tmp ==x_window_max){
            cnt++;
        }
        else if(tmp>x_window_max){
            x_window_max=max(x_window_max, tmp);
            cnt=1;
        }
    }

    if(x_window_max==0){
        cout<<"SAD";
    }
    else{
        cout<<x_window_max<<"\n"<<cnt;
    }

    return 0;
}