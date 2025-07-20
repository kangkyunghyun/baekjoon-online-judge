#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            cout << i << ' ' << x + 1 << ' ' << y + 900'000'000 << '\n';
        }
    }
    return 0;
}