#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, ans = 0;
    cin >> x >> y;
    for (int i = 0, t = 1; i < x; i++) {
        ans += t;
        t *= 10;
    }
    for (int i = 0, t = 1; i < y; i++) {
        ans += t;
        t *= 10;
    }
    cout << ans;
}