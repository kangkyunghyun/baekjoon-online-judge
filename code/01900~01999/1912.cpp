#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int dp[100001] = {0};
    for (int &i : v)
        cin >> i;
    dp[0] = v[0];
    for (int i = 1; i < n; i++)
        dp[i] = max(v[i], dp[i - 1] + v[i]);
    cout << *max_element(dp, dp + n);
}