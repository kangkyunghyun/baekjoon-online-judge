#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[i, j] : v)
        cin >> i >> j;
    v.push_back(v[0]);
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        a += v[i - 1].first * v[i].second;
        b += v[i - 1].second * v[i].first;
    }
    cout.precision(1);
    cout << fixed << (double)abs(a - b) / 2;
}