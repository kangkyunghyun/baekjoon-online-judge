#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, ans = 0;
    cin >> n >> m;
    ans += 2 * n * m;
    int a[100][100] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < m; j++) {
            ans += abs(tmp - a[i][j]);
            tmp = a[i][j];
        }
        ans += tmp;
    }
    for (int i = 0; i < m; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            ans += abs(tmp - a[j][i]);
            tmp = a[j][i];
        }
        ans += tmp;
    }
    cout << ans;
}