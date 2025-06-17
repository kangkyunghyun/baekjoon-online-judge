#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, l, d, t = 0;
    cin >> n >> l >> d;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j)
            v.push_back(0);
        for (int j = 0; j < 5; j++)
            v.push_back(1);
    }
    while (t < v.size())
        if (v[t])
            break;
        else
            t += d;
    cout << t;
}