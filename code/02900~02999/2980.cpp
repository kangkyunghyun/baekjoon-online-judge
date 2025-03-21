#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, l;
    cin >> n >> l;
    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++) {
        int d, r, g;
        cin >> d >> r >> g;
        v[i].first = d;
        v[i].second.first = r;
        v[i].second.second = g;
    }
    int t = 0;
    for (int d = 0, i = 0; d < l; t++, d++) {
        if (d == v[i].first) {
            if (t % (v[i].second.first + v[i].second.second) <= v[i].second.first)
                t += v[i].second.first - (t % (v[i].second.first + v[i].second.second));
            else
                t++, d++;
            i++;
        }
    }
    cout << t;
}