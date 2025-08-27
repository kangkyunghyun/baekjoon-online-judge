#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 18

int n, m;
vector<vector<int>> parent(100001, vector<int>(MAX, -1));
vector<int> depth(100001, -1), length(100001, 0);
vector<pair<int, int>> edge[100001];

void init(int curr) {
    for (auto [next, weigh] : edge[curr])
        if (depth[next] == -1) {
            parent[next][0] = curr;
            depth[next] = depth[curr] + 1;
            length[next] = length[curr] + weigh;
            init(next);
        }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j = 0; diff; j++) {
        if (diff % 2)
            u = parent[u][j];
        diff /= 2;
    }
    if (u != v) {
        for (int j = MAX - 1; j >= 0; j--) {
            if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
                u = parent[u][j];
                v = parent[v][j];
            }
        }
        u = parent[u][0];
    }
    return u;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    depth[0] = 0;
    init(0);
    for (int j = 0; j < MAX; j++)
        for (int i = 1; i < n; i++)
            if (parent[i][j] != -1)
                parent[i][j + 1] = parent[parent[i][j]][j];
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int l = lca(u, v);
        cout << length[u] + length[v] - 2 * length[l] << '\n';
    }
}