#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> graph[51], ans(6);
    int cnt[51] = {0};
    for (int i = 0; i < n + 3; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
    queue<int> q;
    int visited[51] = {0};
    for (int i = 1; i <= 50; i++)
        if (cnt[i] == 1) {
            q.push(i);
            visited[i] = 1;
            ans[5] = i;
        }
    int first = 1, three = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : graph[curr]) {
            if (!visited[next]) {
                if (cnt[next] == 4) {
                    if (first) {
                        ans[4] = next;
                        first = 0;
                    } else {
                        ans[2] = next;
                        visited[next] = 1;
                        continue;
                    }
                } else if (cnt[next] == 3) {
                    if (three == 0) {
                        ans[1] = next;
                        visited[next] = 1;
                        three++;
                        continue;
                    } else if (three == 1)
                        ans[3] = next;
                    else
                        ans[0] = next;
                    three++;
                }
                q.push(next);
                visited[next] = 1;
            }
        }
    }
    if (ans[1] > ans[3])
        swap(ans[1], ans[3]);
    for (int i : ans)
        cout << i << ' ';
}