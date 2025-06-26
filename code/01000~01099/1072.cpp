#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, ans = -1;
    cin >> x >> y;
    int z = 100 * y / x;
    if (z >= 99) {
        cout << ans;
        return 0;
    }
    int left = 0, right = 1e9;
    while (left <= right) {
        int mid = (left + right) / 2;
        int tmp = 100 * (y + mid) / (x + mid);
        if (tmp > z)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left;
}