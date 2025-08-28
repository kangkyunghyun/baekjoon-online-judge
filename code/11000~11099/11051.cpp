#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, dp[1001][1001] = {0};
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        dp[i][1] = i;
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
    cout << dp[n][k];
}