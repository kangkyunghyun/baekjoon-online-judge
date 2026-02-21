#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = INT_MAX;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0, t, s; i < n; i++) {
        cin >> t >> s;
        v.push_back({t, s});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) {
        ans = min(ans, v[i].second);
        ans -= v[i].first;
    }
    cout << (ans < 0 ? -1 : ans);
}