#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a[101][101] = {0}, n, ans = 0;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i < x + 10; ++i)
            for (int j = y; j < y + 10; ++j)
                a[i][j] = 1;
    }
    for (int i = 1; i <= 100; i++)
        ans += accumulate(a[i], a[i] + 100, 0);
    cout << ans;
}