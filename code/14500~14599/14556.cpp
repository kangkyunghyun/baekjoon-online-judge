#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        a = (a * (2 * i - 1)) % 1000000009;
    cout << a;
}