#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (3 * n - m > 0)
        cout << (3 * n - m) * a + b;
    else
        cout << 0;
}