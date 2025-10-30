#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, n;
        cin >> a >> n;
        vector<int> v;
        while (a > 0) {
            v.push_back(a % n);
            a /= n;
        }
        int ans = 1;
        for (int i = 0; i <= (int)v.size() / 2; i++) {
            if (v[i] != v[(int)v.size() - 1 - i]) {
                ans = 0;
                break;
            }
        }
        cout << ans << '\n';
    }
}