#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int idx = s.find('*');
    int sum=0;
    bool odd = false;
    for(int i=0; i<s.length(); i++){
        if(i==idx){
            if(i%2!=0) odd=true;
            continue;
        }
        if(i%2==0){
            sum+=s[i]-'0';
        }
        else{
            sum+=(s[i]-'0')*3;
        }
    }
    //sum이 0 으로 끝나야한다
    if(!odd){
        cout<<10-(sum%10);
    }
    else{
        for(int i=0; i<10; i++){
            if((sum+(3*i)%10)%10==0){
                cout<<i;
                break;
            }
        }
    }
    return 0;
}