#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, pow[20] = {1}, limit = 0;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i < 20; i++) {
        pow[i] = pow[i - 1] * 3;
        if (pow[i] > max(x, y)) {
            limit = i - 1;
            break;
        }
    }
    for (int i = limit; i >= 0; i--)
        if (x > y)
            x -= pow[i];
        else
            y -= pow[i];
    cout << (x == 0 && y == 0);
}