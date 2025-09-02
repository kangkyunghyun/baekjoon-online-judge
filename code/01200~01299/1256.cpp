#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, dp[201][201];
    cin >> n >> m >> k;
    for (int i = 0; i <= 200; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                if (dp[i][j] > 1'000'000'000)
                    dp[i][j] = 1'000'000'000;
            }
    if (dp[n + m][m] < k)
        cout << -1;
    else
        while (!(n == 0 && m == 0))
            if (dp[n + m - 1][m] >= k) {
                cout << 'a';
                n--;
            } else {
                cout << 'z';
                k = k - dp[n + m - 1][m];
                m--;
            }
}