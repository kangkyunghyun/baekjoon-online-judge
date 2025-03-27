#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;
    cout << (a1 * n0 + a0 <= c * n0 && a1 <= c);
}