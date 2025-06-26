#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) {
            int a, t;
            cin >> a >> t;
            if (--t == 0) {
                ans += a;
            } else {
                s.push({a, t});
            }
        } else {
            if (s.empty())
                continue;
            auto [a, t] = s.top();
            s.pop();
            if (--t == 0) {
                ans += a;
            } else {
                s.push({a, t});
            }
        }
    }
    cout << ans;
}