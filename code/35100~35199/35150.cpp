#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b >> n;
        int x = n / 2, y = n - x;
        int xx = x * a + y * b;
        int yy = y * a + x * b;
        cout << xx * yy << '\n';
    }
}