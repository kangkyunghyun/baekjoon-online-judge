#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, dp[301][301] = {0};
    cin >> n >> m >> k;
    vector<pair<int, int>> edge[301];
    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            continue;
        edge[a].push_back({b, c});
    }
    for (auto [d, w] : edge[1])
        dp[d][2] = max(dp[d][2], w);
    for (int i = 2; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (dp[j][i])
                for (auto [d, w] : edge[j])
                    dp[d][i + 1] = max(dp[d][i + 1], dp[j][i] + w);
    cout << *max_element(dp[n] + 2, dp[n] + m + 1);
}