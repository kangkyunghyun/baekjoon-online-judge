#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, dp[501][501] = {0};
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++)
        cin >> v[i] >> v[i + 1];
    for (int diagonal = 1; diagonal < n; diagonal++)
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j]);
        }
    cout << dp[1][n];
}