#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> l(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> l[i];
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (l[i] <= k) {
            dp[i + 1][0] = dp[i][0] + 1;
            dp[i + 1][1] = dp[i][1] + 1;
        } else {
            dp[i + 1][0] = 1;
            dp[i + 1][1] = dp[i][0] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans;
}