#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, r, ans, t = 1;
vector<int> edge[100001];
int visited[100001];

void dfs(int cur, int dep) {
    visited[cur] = 1;
    ans += dep * t++;
    for (int nex : edge[cur])
        if (!visited[nex])
            dfs(nex, dep + 1);
}

signed main() {
    cin >> n >> m >> r;
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(edge[i].begin(), edge[i].end(), greater<>());
    visited[r] = 1;
    dfs(r, 0);
    cout << ans;
}