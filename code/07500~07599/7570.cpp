#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnt = max(cnt, v[t] = v[t - 1] + 1);
    }
    cout << n - cnt;
}