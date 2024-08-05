#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, b;
    cin >> n >> k >> b;
    vector<int> v(n, 0);
    while (b--) {
        int x;
        cin >> x;
        v[x - 1] = 1;
    }
    int ans = k;
    for (int i = 0; i < n - k + 1; i++)
        ans = min(ans, (int)accumulate(v.begin() + i, v.begin() + i + k, 0));
    cout << ans;
}