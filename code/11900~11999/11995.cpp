#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b, n, m, ans = 0;
vector<pair<int, pair<int, int>>> edge;
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
    cin >> a >> b >> n >> m;
    p.resize((n + 1) * (m + 1));
    iota(p.begin(), p.end(), 0);
    vector<int> row{0, b}, col{0, a};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        col.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        row.push_back(x);
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    for (int j = 1; j <= m + 1; j++)
        for (int i = 1; i <= n + 1; i++) {
            int w = col[i] - col[i - 1];
            int h = row[j] - row[j - 1];
            int idx = (j - 1) * (n + 1) + i - 1;
            if (j != m + 1)
                edge.push_back({w, {idx, idx + n + 1}});
            if (i != n + 1)
                edge.push_back({h, {idx, idx + 1}});
        }
    sort(edge.begin(), edge.end());
    for (auto [weight, path] : edge)
        if (find(path.first) != find(path.second)) {
            ans += weight;
            merge(path.first, path.second);
        }
    cout << ans;
}