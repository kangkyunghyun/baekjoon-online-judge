#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, T, ans = 0;
    cin >> n >> k >> T;
    while (n--) {
        int d;
        cin >> d;
        if (T > k)
            T = T + d - abs(T - k);
        else if (T < k)
            T = T + d + abs(T - k);
        else
            T = T + d;
        ans += abs(T - k);
    }
    cout << ans;
}