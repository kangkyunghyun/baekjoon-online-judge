#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int k;
    cin >> k;
    while (k--) {
        string ans = "YES";
        int V, E;
        cin >> V >> E;
        vector<int> edge[200001], visited(200001, -1);
        while (E--) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for (int i = 1; i <= V; i++)
            if (visited[i] == -1) {
                queue<int> q;
                visited[i] = 1;
                q.push(i);
                while (!q.empty()) {
                    int curr = q.front(), flag = 0;
                    q.pop();
                    for (int next : edge[curr]) {
                        if (visited[next] == -1) {
                            visited[next] = !visited[curr];
                            q.push(next);
                        } else if (visited[next] == visited[curr]) {
                            ans = "NO";
                            flag = 1;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
            }
        cout << ans << '\n';
    }
}