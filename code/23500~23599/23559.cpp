#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first - a.second > b.first - b.second;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x, ans = 0;
    cin >> n >> x;
    x -= 1000 * n;
    vector<pair<int, int>> v(n);
    for (auto &[a, b] : v)
        cin >> a >> b;
    sort(v.begin(), v.end(), cmp);
    for (auto [a, b] : v) {
        if (x >= 4000 && a > b) {
            ans += a;
            x -= 4000;
        } else {
            ans += b;
        }
    }
    cout << ans;
}