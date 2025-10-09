#include <bits/stdc++.h>
using namespace std;
using ll = long long;



ll power(int base,int exp,int mod){
    if(exp==1){
        return base%mod;
    }

    ll half = power(base, exp/2, mod);
    if(exp%2==0){
        return (half*half)%mod;
    }
    else{
        return (((half*half)%mod)*(base%mod))%mod;
    }
}

int main(){
    ll a,b,c;
    //10*10mod12=(10mod12*10mod12)mod12
    cin>>a>>b>>c;
    //10의11승 mod12
    
    cout<<power(a,b,c);

}