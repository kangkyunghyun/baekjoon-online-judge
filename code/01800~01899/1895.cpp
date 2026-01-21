#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c, t, ans = 0;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    cin >> t;
    for (int i = 0; i < r - 2; i++) {
        for (int j = 0; j < c - 2; j++) {
            vector<int> tmp;
            tmp.push_back(a[i][j]);
            tmp.push_back(a[i][j + 1]);
            tmp.push_back(a[i][j + 2]);
            tmp.push_back(a[i + 1][j]);
            tmp.push_back(a[i + 1][j + 1]);
            tmp.push_back(a[i + 1][j + 2]);
            tmp.push_back(a[i + 2][j]);
            tmp.push_back(a[i + 2][j + 1]);
            tmp.push_back(a[i + 2][j + 2]);
            sort(tmp.begin(), tmp.end());
            if (tmp[4] >= t)
                ans++;
        }
    }
    cout << ans;
}