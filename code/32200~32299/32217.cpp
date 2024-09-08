#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 180 * (n - 1);
    while (n--) {
        int seta;
        cin >> seta;
        ans -= seta * 2;
    }
    cout << ans;
}