#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int l = 1, r = k, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2, cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += min(mid / i, n);
        if (cnt < k)
            l = mid + 1;
        else
            r = mid - 1, ans = mid;
    }
    cout << ans;
}