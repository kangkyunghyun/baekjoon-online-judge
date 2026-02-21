#include <bits/stdc++.h>
using namespace std;
#define int long long

int V, E, K, ans = 0;
vector<pair<int, pair<int, int>>> edge;
vector<int> p, g;

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
    cin >> V >> E >> K;
    p.resize(V + 1);
    g.resize(V + 1);
    iota(p.begin(), p.end(), 0);
    for (int i = 1, x; i <= V; i++) {
        cin >> x;
        edge.push_back({x, {0, i}});
    }
    fill(g.begin(), g.end(), 1);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        if (min(u, v) + 1 == max(u, v))
            g[min(u, v)] = 0;
        else
            g[V] = 0;
    }
    if (E < 2) {
        cout << "YES";
        return 0;
    }
    for (int i = 1; i <= V; i++)
        if (g[i])
            merge(i, i % V + 1);
    sort(edge.begin(), edge.end());
    for (auto [weight, path] : edge)
        if (find(path.first) != find(path.second)) {
            ans += weight;
            merge(path.first, path.second);
        }
    cout << (ans <= K ? "YES" : "NO");
}