#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000001
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            int l, r, real;
            cin >> l >> r >> real;
            v.push_back({l, min(r, real)});
        }
        sort(v.begin(), v.end());
        int l = -INF, r = -INF;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (l <= k && k <= r)
                ans = max(ans, r);
            if (r < v[i].first) {
                l = v[i].first;
                r = v[i].second;
            } else
                r = max(r, v[i].second);
        }
        if (l <= k && k <= r)
            ans = max(ans, r);
        ans = max(ans, k);
        cout << ans << '
';
    }
}