#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d, h = 0, ans = 0;
    cin >> n >> d;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
        h = max(h, i);
    }
    h = max((int)0, h - d);
    for (int &i : v)
        if (i > h)
            ans += i - h;
    cout << ans;
}