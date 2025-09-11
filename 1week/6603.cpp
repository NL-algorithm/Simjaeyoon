#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int k;

void lotto(const vector<int> &arr, vector<int> &ans)
{ // 들어간 수
    if (ans.size() == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (!ans.empty() && ans.back() >= arr[i])
        {
            continue;
        }
        ans.push_back(arr[i]);
        lotto(arr, ans);
        ans.pop_back();
    }
}

int main()
{
    FastIO;
    while (cin >> k)
    {
        if (k == 0)
            return 0;

        vector<int> arr_s(k);
        for (int i = 0; i < k; i++)
        {
            cin >> arr_s[i];
        }
        vector<int> ans;

        lotto(arr_s, ans);

        cout << "\n";
    }
}