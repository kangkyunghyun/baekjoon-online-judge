#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n, q;
    cin >> m >> n >> q;
    vector<int> a(n), b(m), ans(n, 1);
    for (int &i : a)
        cin >> i;
    for (int i = 1; i <= m; i++) {
        cout << "? " << i << ' ' << i << '\n';
        cout << flush;
        cin >> b[i - 1];
        cout << flush;
    }
    for (int i = 0; i < m; i++) {
        ans[i] = b[i] + 1 <= a[i] ? b[i] + 1 : b[i] - 1;
    }
    cout << "! ";
    for (int i : ans)
        cout << i << ' ';
    cout << flush;
}