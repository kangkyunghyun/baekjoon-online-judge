#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1'000'000'000

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, dp[1000001] = {0, 0, 1};
    cin >> n;
    for (int i = 3; i <= n; i++)
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
    cout << dp[n];
}