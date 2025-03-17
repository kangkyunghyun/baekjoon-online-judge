#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, r, c;
    cin >> n >> r >> c;
    if (n == 3) {
        if (r == 2 && c == 2)
            cout << 1;
        else
            cout << 4;
    } else if (n % 2 == 0) {
        cout << n * n / 2;
    } else {
        if ((r + c) % 2 == 0)
            cout << n * n / 2 + 1;
        else
            cout << n * n / 2;
    }
}