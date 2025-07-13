#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000001

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    vector<int> len;
    int l = -INF, r = -INF;
    for (int i = 0; i < n; i++)
        if (r < v[i].first) {
            l = v[i].first;
            len.push_back(l - max(r, 0LL) - 1);
            r = v[i].second;
        } else
            r = max(r, v[i].second);
    if (r < h)
        len.push_back(min(h - r, h));

    sort(len.begin(), len.end());
    vector<int> pre(len.size() + 1, 0);
    for (int i = 1; i <= len.size(); i++)
        pre[i] = pre[i - 1] + len[i - 1];
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        int it = lower_bound(len.begin(), len.end(), t) - len.begin();
        int size = len.size() - it;
        cout << pre[len.size()] - pre[it] - size * (t - 1) << '\n';
    }
    return 0;
}
