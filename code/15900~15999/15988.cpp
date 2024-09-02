#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    int dp[1000001]={0};
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i <= 1000000; i++)
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}