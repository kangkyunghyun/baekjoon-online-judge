#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, x;
int visited[100001];
vector<int> edge[2][100001];

int dfs(int curr, int reverse) {
    int ret = 1;
    visited[curr] = 1;
    for (int next : edge[reverse][curr])
        if (!visited[next])
            ret += dfs(next, reverse);
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x;
    while (m--) {
        int a, b;
        cin >> a >> b;
        edge[0][b].push_back(a);
        edge[1][a].push_back(b);
    }
    cout << dfs(x, 0) << ' ' << n - dfs(x, 1) + 1;
}