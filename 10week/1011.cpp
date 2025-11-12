#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T;
    cin>>T;
    for(int t=0; t<T; t++){
        ll x,y;//0<=x<y<2^31
        cin>>x>>y;
        ll dist = y-x;
        ll k=1;//처음 k값
        ll go=0;
        int cnt=0;
        while(go<dist){
            go+=k*2;
            cnt+=2;
            if(go>dist){
                go-=k*2;
                cnt-=2;
                k--;
                break;
            }
            k++;
        }
        ll remain = dist-go;
        for(int i=k+1; i>=1; i--){
            if(remain>=i){
                remain-=i;
                cnt++;
            }
        }
    
        cout<<cnt<<"\n";
    }
}