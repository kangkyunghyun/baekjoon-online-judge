#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, graph[101] = {0};
    vector<int> visited(101, -1);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x] = y;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u] = v;
    }
    queue<int> q;
    q.push(1);
    visited[1] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int next = curr + i;
            if (next > 100)
                continue;
            if (visited[next] == -1) {
                visited[next] = visited[curr] + 1;
                int flag = 1;
                if (graph[next]) {
                    flag = 0;
                    if (visited[graph[next]] == -1) {
                        next = graph[next];
                        visited[next] = visited[curr] + 1;
                        q.push(next);
                    }
                }
                if (flag)
                    q.push(next);
            }
        }
    }
    cout << visited[100];
}