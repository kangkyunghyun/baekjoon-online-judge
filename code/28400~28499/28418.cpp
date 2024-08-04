#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int a1 = a * d * d, b1 = 2 * a * d * e + b * d, c1 = a * e * e + b * e + c;
    int a2 = a * d, b2 = b * d, c2 = c * d + e;
    int A = a1 - a2, B = b1 - b2, C = c1 - c2;
    string ans;
    if (A == 0) {
        if (B == 0) {
            if (C == 0)
                ans = "Nice";
            else
                ans = "Head on";
        } else
            ans = "Remember my character";
    } else {
        int D = B * B - 4 * A * C;
        if (D > 0)
            ans = "Go ahead";
        else if (D < 0)
            ans = ans = "Head on";
        else
            ans = "Remember my character";
    }
    cout << ans;
}