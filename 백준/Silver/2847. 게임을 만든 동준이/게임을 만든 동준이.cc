#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;
    for (int i = n - 1; i > 0; i--) {
        if (v[i - 1] >= v[i]) {
            ans += v[i - 1] - v[i] + 1;
            v[i - 1] = v[i] - 1;
        }
    }
    cout << ans;
}