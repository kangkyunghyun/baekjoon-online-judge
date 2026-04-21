#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, b, c, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    cin >> b >> c;
    for (int& i : a) {
        i -= b;
        ans++;
        if (i > 0) {
            ans += i / c;
            if (i % c)
                ans++;
        }
    }
    cout << ans;
}