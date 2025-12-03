#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> v[i];
    int ans = v[0];
    for (int i = 1; i <= n; i++) {
        if ((v[0] == 1 && i == 1) || v[i] == 1)
            ans = (ans + v[i]) % MOD;
        else
            ans = (ans * v[i]) % MOD;
    }
    cout << ans;
}