#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> p;

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x < y)
        p[y] = x;
    else
        p[x] = y;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
    while(m--) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int ans = 1, MOD = 1000000007;
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cnt[find(i)]++;
    for (int i = 1; i <= n; i++)
        if (cnt[i])
            ans = ((ans % MOD) * (cnt[i] % MOD)) % MOD;
    cout << ans;
}