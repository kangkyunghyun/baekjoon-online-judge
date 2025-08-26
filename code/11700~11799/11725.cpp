#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> edge[100001], visited(100001, -1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    visited[1] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : edge[curr])
            if (visited[next] == -1) {
                q.push(next);
                visited[next] = curr;
            }
    }
    for (int i = 2; i <= n; i++)
        cout << visited[i] << '\n';
}