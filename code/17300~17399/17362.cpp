#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0, rev = 0;
    cin >> n;
    while (n--) {
        if (!rev) {
            ans++;
        } else {
            ans--;
        }
        if ((!rev && ans == 5) || (rev && ans == 1))
            rev = !rev;
    }
    cout << ans;
}