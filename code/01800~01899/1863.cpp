#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    stack<int> s;
    for (int i = 0; i <= n; i++) {
        int x, y;
        if (i != n)
            cin >> x >> y;
        else
            y = 0;
        while (!s.empty() && s.top() >= y) {
            if (s.top() != y)
                ans++;
            s.pop();
        }
        s.push(y);
    }
    cout << ans;
}