#include <bits/stdc++.h>
using namespace std;

void a(int k, int i){//번호
    int kk = ceil(log2(k));
    int ii = ceil(log2(i));
    if(kk==ii){
        a(k-pow(2,kk-1), i-pow(2,ii-1));
    }
    else{
        cout<<max(kk,ii);
    }
}

int main(){
    int n, K, I;
    cin>>n>>K>>I;

    a(K,I);
    
    return 0;
}