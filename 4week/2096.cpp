#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> max_cache(3);
    cin >> n;
    cin >> max_cache[0] >> max_cache[1] >> max_cache[2];
    vector<int> min_cache(max_cache);

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> pre_max_cache(max_cache);
        vector<int> pre_min_cache(min_cache);

        max_cache[0] = max(pre_max_cache[0] + a, pre_max_cache[1] + a);
        max_cache[1] = max({pre_max_cache[0] + b, pre_max_cache[1] + b, pre_max_cache[2] + b});
        max_cache[2] = max(pre_max_cache[1] + c, pre_max_cache[2] + c);

        min_cache[0] = min(pre_min_cache[0] + a, pre_min_cache[1] + a);
        min_cache[1] = min({pre_min_cache[0] + b, pre_min_cache[1] + b, pre_min_cache[2] + b});
        min_cache[2] = min(pre_min_cache[1] + c, pre_min_cache[2] + c);
    }
    int max_sum = 0, min_sum = 987654321;

    for (int i = 0; i < 3; i++) {
        max_sum = max(max_sum, max_cache[i]);
        min_sum = min(min_sum, min_cache[i]);
    }
    cout << max_sum << " " << min_sum;

    return 0;
}