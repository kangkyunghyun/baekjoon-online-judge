#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int d(int y) {
    int sum = 0;
    while (y > 0) {
        sum += y % 10;
        y /= 10;
    }
    return sum;
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int ans = 0;
        for (int y = x; y <= x + 100; y++)
            if (y - d(y) == x)
                ans++;
        cout << ans << '
';
    }
}