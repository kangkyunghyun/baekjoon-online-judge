#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int f, r, n, ans = 0;
        cin >> f >> r >> n;
        ans += 2 * f + r + 1;
        vector<vector<int>> v(f + 1);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        for (int i = 1; i <= f; i++) {
            v[i].push_back(0);
            v[i].push_back(r + 1);
            sort(v[i].begin(), v[i].end());
            int tmp = 987654321;
            for (int j = 0; j < v[i].size() - 1; j++)
                tmp = min(tmp, v[i][j] + r - v[i][j + 1] + 1);
            ans += 2 * tmp;
        }
        cout << ans << '\n';
    }
}