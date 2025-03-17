#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int y = 2024, m = 8;
    while (--n) {
        if (m <= 5) {
            m += 7;
        } else {
            y += 1;
            m -= 5;
        }
    }
    cout << y << ' ' << m;
}