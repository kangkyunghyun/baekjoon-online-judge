#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    if (k > 36) {
        cout << "MEGA";
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                if (dp[i - 1][j] > 0)
                    dp[i][j] = max(0LL, dp[i - 1][j] + a[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j - 1] * 2;
                if (dp[i - 1][j] > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i - 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)
        ans = max(ans, dp[n][i]);
    if (ans <= 0)
        cout << -1;
    else
        cout << (ans > 1e11 ? "MEGA" : to_string(ans));
}