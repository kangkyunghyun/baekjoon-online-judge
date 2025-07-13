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
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    map<int, int> m;
    m[v[0]] = 0;
    vector<map<int, int>> group;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1] + 1)
            merge(i, i - 1);
        else if (v[i] <= v[i - 1]) {
            group.push_back(m);
            m.clear();
        }
        m[v[i]] = i;
    }
    group.push_back(m);
    for (int i = 0; i < group.size() - 1; i++)
        for (auto [val, idx] : group[i])
            if (group[i + 1].find(val) != group[i + 1].end())
                merge(group[i][val], group[i + 1][val]);
    set<int> ans;
    for (int i : p)
        ans.insert(find(i));
    cout << ans.size() << '\n'
         << n;
    return 0;
}