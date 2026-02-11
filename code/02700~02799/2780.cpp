#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1234567

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    int dp[1001][10];
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= 1000; i++) {
        dp[i][0] = dp[i - 1][7] % MOD;
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][4]) % MOD;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % MOD;
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][6]) % MOD;
        dp[i][4] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % MOD;
        dp[i][5] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % MOD;
        dp[i][6] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % MOD;
        dp[i][7] = (dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8]) % MOD;
        dp[i][8] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % MOD;
        dp[i][9] = (dp[i - 1][6] + dp[i - 1][8]) % MOD;
    }
    while (t--) {
        int n, ans = 0;
        cin >> n;
        for (int i = 0; i < 10; i++)
            ans += dp[n][i];
        cout << ans % MOD << '\n';
    }
}