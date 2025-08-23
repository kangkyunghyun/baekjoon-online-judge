#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 1;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    for (int i = 0; i < n; i++) {
        if (i + 1 == v[i])
            ans = (ans * (n - 1)) % MOD;
        else
            ans = (ans * (n - 2)) % MOD;
    }
    cout << ans;
}