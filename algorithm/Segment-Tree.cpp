// O(logN)
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> t;

void init() {
    for (int i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}

void update(int p, int v) {
    for (t[p += n] = v; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

// [l, r)
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, k;
    cin >> n >> m >> k;
    t.resize(2 * n);
    for (int i = n; i < 2 * n; i++)
        cin >> t[i];
    init();
    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(b - 1, c);
        else
            cout << query(b - 1, c) << '\n';
    }
}