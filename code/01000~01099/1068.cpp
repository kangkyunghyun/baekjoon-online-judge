#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, ans = 0;
    cin >> n;
    vector<int> edge[50], visited(50, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1)
            continue;
        edge[x].push_back(i);
    }
    cin >> m;
    queue<int> q;
    q.push(m);
    visited[m] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : edge[curr]) {
            q.push(next);
            visited[next] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        if (visited[i])
            continue;
        for (int next : edge[i])
            if (!visited[next])
                cnt++;
        if (!cnt)
            ans++;
    }
    cout << ans;
}