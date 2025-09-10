#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a, ans = 0;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += min(abs(x - a), min(360 - a + x, 360 - x + a));
        a = x;
    }
    cout << ans;
}