// Sweeping O(NlogN)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000001

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int ans = 0, l = -INF, r = -INF;
    for (int i = 0; i < n; i++)
        if (r < v[i].first) {
            ans += r - l;
            l = v[i].first;
            r = v[i].second;
        } else
            r = max(r, v[i].second);
    ans += r - l;
    cout << ans;
    return 0;
}