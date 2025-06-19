#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = n - 1; i >= 0; --i)
        if (v[i] == n) {
            n--;
            ans--;
        }
    cout << ans;
}