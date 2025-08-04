#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, r, cnt = 1;
int visited[100001];
vector<int> graph[100001];

void dfs(int curr) {
    visited[curr] = cnt++;
    for (int next : graph[curr])
        if (!visited[next])
            dfs(next);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> r;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= 100000; i++)
        sort(graph[i].begin(), graph[i].end(), greater<>());
    dfs(r);
    for (int i = 1; i <= n; i++)
        cout << visited[i] << '\n';
}