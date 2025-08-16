#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> sum(n + 1, 0), remain(m, 0);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] = (sum[i] % m + sum[i - 1]) % m;
        remain[sum[i]]++;
    }
    ans += remain[0];
    for (int i = 0; i < m; i++)
        if (remain[i])
            ans += remain[i] * (remain[i] - 1) / 2;
    cout << ans;
}