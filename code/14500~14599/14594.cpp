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
    while (m--) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i < y; i++)
            merge(i, y);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (p[i] == i)
            ans++;
    cout << ans;
}