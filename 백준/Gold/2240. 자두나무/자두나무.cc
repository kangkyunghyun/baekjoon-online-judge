#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t, w;
    cin >> t >> w;
    vector<int> v(t + 1);
    for (int i = 1; i <= t; i++)
        cin >> v[i];
    int dp[31][1001] = {0};
    for (int time = 1; time <= t; time++) {
        for (int cnt = 0; cnt <= w; cnt++) {
            int pos = cnt % 2 + 1;
            if (cnt == 0)
                dp[cnt][time] = dp[cnt][time - 1] + (pos == v[time]);
            else
                dp[cnt][time] = max(dp[cnt][time - 1], dp[cnt - 1][time - 1]) + (pos == v[time]);
        }
    }
    int ans = 0;
    for (int cnt = 0; cnt <= w; cnt++)
        ans = max(ans, dp[cnt][t]);
    cout << ans;
}