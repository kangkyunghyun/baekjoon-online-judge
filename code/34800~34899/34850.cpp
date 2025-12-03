#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, p, a, b;
    cin >> x >> y >> p >> a >> b;
    p += (y - 1) * b;
    int ans = 0;
    while (x--) {
        ans += p;
        p -= a;
    }
    cout << ans;
}