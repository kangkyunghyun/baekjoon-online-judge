#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int dp[1000001] = {0, 1, 2};
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    cout << dp[n];
}