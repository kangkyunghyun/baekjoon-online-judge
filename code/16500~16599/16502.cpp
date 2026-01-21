#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<pair<int, double>> a[4];
vector<double> ans(4, 0.0);

void dfs(int u, double prob, int depth) {
    if (depth == n) {
        ans[u] += prob;
        return;
    }
    for (auto [v, p] : a[u]) {
        dfs(v, prob * p, depth + 1);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        char x, y;
        double p;
        cin >> x >> y >> p;
        int u = x - 'A', v = y - 'A';
        a[u].push_back({v, p});
    }
    for (int i = 0; i < 4; i++) {
        dfs(i, 0.25, 0);
    }
    cout.precision(2);
    cout << fixed;
    for (auto i : ans)
        cout << i * 100 << '\n';
}