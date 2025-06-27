#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n) {
        int tmp = 1, ans = 1;
        while (tmp % n != 0) {
            tmp = (tmp * 10 + 1) % n;
            ans++;
        }
        cout << ans << '\n';
    }
}