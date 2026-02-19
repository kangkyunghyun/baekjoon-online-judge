#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000001

int n, q;
vector<pair<pair<int, int>, int>> v;
vector<int> p;

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x < y)
        p[y] = x;
    else
        p[x] = y;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
    for (int i = 1; i <= n; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        v.push_back({{x1, x2}, i});
    }
    sort(v.begin(), v.end());
    int l = -INF, r = -INF, prev = 0;
    for (auto [xy, i] : v) {
        auto [x, y] = xy;
        if (r < x) {
            l = x;
            r = y;
            prev = i;
        } else {
            r = max(r, y);
            if (!prev) {
                prev = i;
                continue;
            }
            merge(prev, i);
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (find(a) == find(b)) << '\n';
    }
}