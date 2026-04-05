#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
        vector<int> tmp = v[i];
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for (int j = 0; j < n; j++)
            v[i][j] = lower_bound(tmp.begin(), tmp.end(), v[i][j]) - tmp.begin();
    }
    sort(v.begin(), v.end());
    int ans = 0, cnt = 1;
    for (int i = 1; i < m; i++) {
        if (v[i] == v[i - 1])
            cnt++;
        else {
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    ans += cnt * (cnt - 1) / 2;
    cout << ans;
}