#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, u, d, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> u >> d;
    vector<char> ans(n, ' ');
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            if (u > 0) {
                u--;
                ans[i] = 'U';
            } else {
                cout << "NO";
                return 0;
            }
        } else if (v[i] == 2) {
            if (d > 0) {
                d--;
                ans[i] = 'D';
            } else {
                cout << "NO";
                return 0;
            }
        } else {
            if (u > 0) {
                u--;
                ans[i] = 'U';
            } else if (d > 0) {
                d--;
                ans[i] = 'D';
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (auto i : ans)
        cout << i;
}