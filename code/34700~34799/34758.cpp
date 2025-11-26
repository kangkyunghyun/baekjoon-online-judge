#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, n;
    cin >> x >> y >> n;
    while (n--) {
        int a, b, ans = 0;
        cin >> a >> b;
        if (x != a)
            ans++;
        if (y != b)
            ans++;
        cout << max(0, ans - 1) << '\n';
    }
}