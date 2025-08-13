#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n;
    vector<int> v(n), sum(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n - 1; i++)
        v[i] = (v[i] > v[i + 1]);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + v[i - 1];
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << sum[y - 1] - sum[x - 1] << '\n';
    }
}