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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        vector<pair<pair<int, int>, int>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].first.first >> v[i].first.second >> v[i].second;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                auto [pos1, r1] = v[i];
                auto [pos2, r2] = v[j];
                auto [x1, y1] = pos1;
                auto [x2, y2] = pos2;
                if (pow(x1 - x2, 2) + pow(y1 - y2, 2) <= pow(r1 + r2, 2))
                    merge(i + 1, j + 1);
            }
        }
        set<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(find(i));
        cout << s.size() << '\n';
    }
}