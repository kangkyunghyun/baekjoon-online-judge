#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, m, x = 0;
    cin >> a >> m;
    while (++x) {
        if ((x * m + 1) % a == 0) {
            cout << (x * m + 1) / a;
            break;
        }
    }
}