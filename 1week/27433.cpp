#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

long long factorial(int n){
    if(n==1||n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<factorial(n);
}