#include <bits/stdc++.h>
using namespace std;

int n;
bool test(const vector<int> &arr, int a, int b)
{
    int i = 1;
    while (1)
    {
        if (arr[i] != arr[i - 1] * a + b)
        {
            return false;
        }
        if (i == n - 1)
        {
            return true;
        }
        i++;
    }
}
int next(const vector<int> &arr, int a, int b, int i)
{
    return arr[i] * a + b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans;
    vector<int> rel;
    if (n == 1)
    {
        cout << 'A';
        return 0;
    }
    else if (n == 2)
    {
        if (arr[0] != arr[1])
        {
            cout << 'A';
        }
        else
        {
            cout << arr[0];
        }
        return 0;
    }
    else
    {
        int cnt = 0;
        for (int a = -200; a <= 199; a++)
        {
            int b = arr[1] - arr[0] * a;
            ans = next(arr, a, b, 1);
            if (ans > 100 || ans < -100)
                continue;
            if (test(arr, a, b))
            {
                int t=next(arr,a,b,n-1);
                if(rel.empty()){
                    rel.push_back(t);
                    cnt++;
                }
                else{
                    if(rel.back()!=t){
                        cout<<'A';
                        return 0;
                    }
                }
            }
            if (cnt >= 2)
            {
                cout << 'A';
                return 0;
            }
        }

        if (cnt == 1)
        {
            cout << rel[0];
            return 0;
        }
        if (cnt == 0)
        {
            cout << 'B';
            return 0;
        }
    }
}