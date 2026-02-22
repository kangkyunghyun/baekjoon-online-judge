#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, c, h, k;
vector<int> p, cnt;
vector<pair<int, int>> tmp;
priority_queue<int> pq;

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x < y) {
        p[y] = x;
        cnt[x] += cnt[y];
        cnt[y] = 0;
    } else {
        p[x] = y;
        cnt[y] += cnt[x];
        cnt[x] = 0;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
    cnt.resize(n + 1, 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (find(x) != find(y))
            merge(x, y);
    }
    cin >> c >> h >> k;
    for (int i = 1; i <= n; i++)
        if (cnt[i] && find(i) != find(c) && find(i) != find(h))
            pq.push(cnt[i]);
    while (k--) {
        cnt[find(c)] += pq.top();
        pq.pop();
    }
    cout << cnt[find(c)];
}