#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
    }
    int sum = 0;
    while (m--) {
        int t, p;
        cin >> t >> p;
        sum += p;
    }
    cout.precision(5);
    cout << fixed << (double)sum / n;
}