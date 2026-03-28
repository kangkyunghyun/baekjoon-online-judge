#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1, 0), sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 2; i < n; i++)
        ans = max({ans, sum[n] * 2 - a[1] - a[i] - sum[i], sum[n - 1] - a[i] + sum[i - 1], sum[i] - a[1] + sum[n - 1] - sum[i - 1]});
    cout << ans;
}