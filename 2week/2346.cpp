#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;

int main()
{
    FastIO;
    int n;
    cin >> n;
    deque<pair<int, int>> paper(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        paper[i] = {a, i + 1};
    }
    int index = 0;
    while (!paper.empty())
    {
        cout << paper[index].second << " ";

        int step = paper[index].first;
        paper.erase(paper.begin() + index);

        if (paper.empty())
        {
            break;
        }
        int size = paper.size();

        if(step>0){
            index = (index+step-1)%size;
        }
        else{
            index = (index+step)%size;
            if(index<0){
                index+=size;
            }
        }
    }
}