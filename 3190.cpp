#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

class Snake{
    private:
        pair<int,int> head; //머리좌표
        pair<int,int> tail; //꼬리좌표
        int direction = 1;//시작은 오른쪽
    public:
        int move(){
            
        }
};

int main()
{
    FastIO;
    int n, k, l;
    cin >> n >> k;
    vector<pair<int, int>> apple(k);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        apple.push_back({a, b});
    }
    cin >> l;
    vector<pair<int, char>> status(l);
    for (int i = 0; i < l; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        status.push_back({a, b});
    }


}