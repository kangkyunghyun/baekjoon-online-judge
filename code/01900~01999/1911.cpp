#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1'000'000'001

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].second--;
    }
    sort(v.begin(), v.end());
    int ans = 0, idx = 0;
    for (auto [i, j] : v) {
        idx = max(idx, i);
        while (idx <= j) {
            ans++;
            idx += l;
        }
    }
    cout << ans;
    return 0;
}