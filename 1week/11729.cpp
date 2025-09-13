#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int hanoi(int n)
{
    if (n == 1)
        return 1;
    else
    {
        return hanoi(n - 1) * 2 + 1;
    }
}

void hanoi(int n, int from, int tmp, int end){//from에서 tmp를 거쳐 end로
    if(n==1){
        cout<<from<<" "<< end<<"\n";
    }
    else{
        hanoi(n-1, from, end, tmp);//마지막 하나를 제외하고 tmp로 이동
        cout<<from<<" "<<end<<"\n";//마지막 하나를 이동
        hanoi(n-1, tmp, from, end);//tmp에 올려둔걸 end로 이동
    }
}

int main()
{
    FastIO;
    int n;
    cin >> n;

    cout << hanoi(n)<<"\n";

    int a=1,b=2,c=3;

    hanoi(n, a, b, c);
}