#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> t(n + 1), p(n + 1), dp(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];
    for (int i = n; i > 0; i--)
        if (i + t[i] > n + 1)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
    cout << dp[1];
}