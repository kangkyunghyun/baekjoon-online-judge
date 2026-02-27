#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        if (a[i] == k)
            ans++;
    }
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        ans += m[a[i] - k];
        m[a[i]]++;
    }
    cout << ans;
}