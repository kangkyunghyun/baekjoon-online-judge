#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, d = 0, ans = 0;
    cin >> n >> m;
    vector<int> a(101, 0), b(101, 0);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 1; j <= x; j++)
            a[d + j] = y;
        d += x;
    }
    d = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 1; j <= x; j++)
            b[d + j] = y;
        d += x;
    }
    for (int i = 0; i <= 100; i++)
        ans = max(ans, b[i] - a[i]);
    cout << ans;
}