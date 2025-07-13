#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, sum = 0, t = 1e10;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        sum += x;
        t = min(t, x);
    }
    cout << sum - t;
}