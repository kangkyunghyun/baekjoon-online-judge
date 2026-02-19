#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int k;
    cin >> k;
    int a[46] = {1, 0}, b[46] = {0, 1};
    for (int i = 2; i <= k; i++)
        a[i] = a[i - 1] + a[i - 2], b[i] = b[i - 1] + b[i - 2];
    cout << a[k] << ' ' << b[k];
}