#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt = 0, f = 1, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p == 0) {
            if (f > 0) {
                f = -1;
            } else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        } else {
            cnt++;
        }
        f++;
    }
    ans = max(ans, cnt);
    cout << ans;
}