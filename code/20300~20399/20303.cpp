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
    int n, m, k;
    int c[30001];
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    vector<int> cnt(30001, 1);
    for (int i = 1; i <= n; i++) {
        if (p[i] != i) {
            int parent = find(i);
            c[parent] += c[i];
            cnt[parent] += cnt[i];
        }
    }
    vector<int> knapsack(k, 0);
    for (int i = 1; i <= n; i++)
        if (p[i] == i) {
            int w = cnt[i], v = c[i];
            for (int j = k - 1; j >= w; j--)
                knapsack[j] = max(knapsack[j], knapsack[j - w] + v);
        }
    cout << knapsack[k - 1];
}