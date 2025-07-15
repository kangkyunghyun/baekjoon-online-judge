#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
        x[i] = a[i].first;
    }
    sort(a.begin(), a.end());
    sort(x.begin(), x.end());
    int pre[200001][2] = {0};
    for (int i = 1; i <= n; i++) {
        pre[i][0] = pre[i - 1][0] + a[i - 1].first * a[i - 1].second;
        pre[i][1] = pre[i - 1][1] + a[i - 1].second;
    }
    while (q--) {
        int t;
        cin >> t;
        int idx = lower_bound(x.begin(), x.end(), t) - x.begin();
        cout << pre[n][0] - 2 * pre[idx][0] - t * (pre[n][1] - 2 * pre[idx][1]) << '\n';
    }
}