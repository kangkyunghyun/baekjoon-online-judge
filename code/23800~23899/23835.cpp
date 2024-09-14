#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q;
vector<int> adj[1001];
int arr[1001], visited[1001];

int dfs(int cnt, int x, int curr) {
    if (curr == x) {
        arr[curr] += cnt;
        return 1;
    }
    for (int i : adj[curr]) {
        if (!visited[i]) {
            visited[i] = 1;
            arr[curr] += cnt;
            int tmp = dfs(cnt + 1, x, i);
            visited[i] = 0;
            if (tmp == 1)
                return 1;
            arr[curr] -= cnt;
        }
    }
    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            visited[u] = 1;
            dfs(0, v, u);
            visited[u] = 0;
        } else {
            int x;
            cin >> x;
            cout << arr[x] << '\n';
        }
    }
}