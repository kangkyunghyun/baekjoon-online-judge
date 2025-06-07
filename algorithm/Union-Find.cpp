// Union Find
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
    int n;
    cin >> n;
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
    while (1) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    return 0;
}