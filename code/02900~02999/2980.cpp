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
    for (int d = 0, i = 0; d < l;) {
        if (i < n) {
            int pos = v[i].first;
            int r = v[i].second.first;
            int g = v[i].second.second;
            int cycle = r + g;
            if (d == pos) {
                if (t % cycle <= r)
                    t += r - (t % cycle);
                else
                    t++, d++;
                i++;
                continue;
            }
        }
        t++, d++;
    }
    cout << t;
}