#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<int> edge[300001], visited(300001, -1), ans;
    while (m--) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    queue<int> q;
    q.push(x);
    visited[x] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : edge[curr]) {
            if (visited[next] == -1) {
                visited[next] = visited[curr] + 1;
                if (visited[next] == k)
                    ans.push_back(next);
                else
                    q.push(next);
            }
        }
    }
    if (ans.empty())
        cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for (int i : ans)
            cout << i << '\n';
    }
}