#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    int q;
    cin >> q;
    while (q--) {
        int a, c, x;
        cin >> a >> c;
        if (a == 1) {
            cin >> x;
            int y = x;
            for (int i = c + 1; i <= n && x; i++) {
                int tmp = min(d[i], x);
                d[i] += tmp;
                x -= tmp;
            }
            x = y;
            for (int i = c; i > 0 && x; i--) {
                int tmp = min(d[i], x);
                d[i] += tmp;
                x -= tmp;
            }
        } else {
            cout << d[c] << '\n';
        }
    }
}