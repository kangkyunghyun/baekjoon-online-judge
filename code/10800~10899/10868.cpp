#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> t;

void init() {
    for (int i = n - 1; i > 0; --i)
        t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void update(int p, int v) {
    for (t[p += n] = v; p > 1; p >>= 1)
        t[p >> 1] = min(t[p], t[p ^ 1]);
}

// [l, r)
int query(int l, int r) {
    int res = 1e9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = min(res, t[l++]);
        if (r & 1)
            res = min(res, t[--r]);
    }
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int m;
    cin >> n >> m;
    t.resize(2 * n);
    for (int i = n; i < 2 * n; i++)
        cin >> t[i];
    init();
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << query(a - 1, b) << '\n';
    }
}