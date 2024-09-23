#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, p, q, r, s, ans = 0;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n+1, 0);
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            a[i] = p * a[i/2] + q;
        } else {
            a[i] = r * a[i/2] + s;
        }
    }
    cout << accumulate(a.begin(), a.end(), 0);
}