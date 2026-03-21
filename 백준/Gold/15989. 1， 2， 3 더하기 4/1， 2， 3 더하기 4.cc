#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, dp[10001];

signed main() {
    dp[0] = 1;
    for (int i = 1; i <= 3; i++)
        for (int j = i; j <= 10000; j++)
            dp[j] += dp[j - i];
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}