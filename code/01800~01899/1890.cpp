#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100][100], dp[100][100];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!dp[i][j] || !a[i][j])
                continue;
            if (i + a[i][j] < n)
                dp[i + a[i][j]][j] += dp[i][j];
            if (j + a[i][j] < n)
                dp[i][j + a[i][j]] += dp[i][j];
        }
    }
    cout << dp[n - 1][n - 1];
}