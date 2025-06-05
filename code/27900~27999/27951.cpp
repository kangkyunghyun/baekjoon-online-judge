#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, u, d, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    cin >> u >> d;
    vector<char> ans(n, ' ');
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            if (u == 0) {
                cout << "NO";
                return 0;
            }
            ans[i] = 'U';
            u--;
        } else if (v[i] == 2) {
            if (d == 0) {
                cout << "NO";
                return 0;
            }
            ans[i] = 'D';
            d--;
        } else {
            cnt++;
        }
    }
    if ((u == 0 && d == 0) || cnt == u + d) {
        cout << "YES\n";
        for (auto &i : ans) {
            if (i == ' ') {
                if (u > 0) {
                    cout << 'U';
                    u--;
                } else {
                    cout << 'D';
                }
            } else {
                cout << i;
            }
        }
    } else {
        cout << "NO";
    }
}