#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, dp[31];
    cin >> n;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
    int x = n % 2 ? dp[n / 2] : dp[n / 2] + dp[n / 2 - 1] * 2;
    cout << (dp[n] - x) / 2 + x;
}