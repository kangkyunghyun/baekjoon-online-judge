#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;
    int x = 1, y = 1;
    for (int i = 0; i < n; i++) {
        x += a;
        y += b;
        if (x < y)
            swap(x, y);
        if (x == y)
            y--;
    }
    cout << x << ' ' << y;
}