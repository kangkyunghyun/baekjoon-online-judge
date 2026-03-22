#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, k, a[501], dp[501][501];

int dfs(int s, int e) {
    if (s == e)
        return dp[s][e] = 0;
    if (dp[s][e] != -1)
        return dp[s][e];
    dp[s][e] = INT_MAX;
    for (int i = s; i < e; i++)
        dp[s][e] = min(dp[s][e], dfs(s, i) + dfs(i + 1, e) + a[e] - a[s - 1]);
    return dp[s][e];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> k;
        memset(a, 0, sizeof(a));
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        cout << dfs(1, k) << '\n';
    }
}