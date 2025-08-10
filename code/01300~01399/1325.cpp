#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, MAX = 0;
    cin >> n >> m;
    vector<int> graph[10001], ans;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        int visited[10001] = {0};
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : graph[curr])
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = 1;
                }
        }
        int M = accumulate(visited, visited + 10001, 0);
        if (MAX == M) {
            ans.push_back(i);
        } else if (MAX < M) {
            MAX = M;
            ans.clear();
            ans.push_back(i);
        }
    }
    for (int i : ans)
        cout << i << ' ';
}