#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 1e9

int n;
vector<pair<int, int>> t;

void init() {
    for (int i = n - 1; i > 0; --i) {
        t[i].first = max(t[i << 1].first, t[i << 1 | 1].first);
        t[i].second = min(t[i << 1].second, t[i << 1 | 1].second);
    }
}

// [l, r)
pair<int, int> query(int l, int r) {
    pair<int, int> res = {0, MAX};
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            res.first = max(res.first, t[l].first);
            res.second = min(res.second, t[l++].second);
        }
        if (r & 1) {
            res.first = max(res.first, t[--r].first);
            res.second = min(res.second, t[r].second);
        }
    }
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int m;
    cin >> n >> m;
    t.resize(2 * n);
    for (int i = n; i < 2 * n; i++) {
        cin >> t[i].first;
        t[i].second = t[i].first;
    }
    init();
    while (m--) {
        int a, b;
        cin >> a >> b;
        auto [y, x] = query(a - 1, b);
        cout << x << ' ' << y << '\n';
    }
}