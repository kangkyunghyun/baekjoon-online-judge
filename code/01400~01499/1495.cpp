#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, s, m;
    cin >> n >> s >> m;
    vector<int> v(n + 1, s);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][s] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j]) {
                if (j + v[i] <= m)
                    dp[i][j + v[i]] = 1;
                if (j - v[i] >= 0)
                    dp[i][j - v[i]] = 1;
            }
        }
    }
    for (int i = m; i >= 0; i--)
        if (dp[n][i]) {
            cout << i;
            return 0;
        }
    cout << -1;
}