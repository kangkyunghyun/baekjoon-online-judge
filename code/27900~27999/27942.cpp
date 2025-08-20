#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string route = "\n";
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0)), sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + arr[i][j] - sum[i - 1][j - 1];
    int x1 = n / 2, y1 = n / 2, x2 = n / 2 + 1, y2 = n / 2 + 1;
    while (1) {
        vector<int> udlr(4, 0);
        if (y1 > 1)
            udlr[0] = sum[y1 - 1][x2] - sum[y1 - 1][x1 - 1] - sum[y1 - 2][x2] + sum[y1 - 2][x1 - 1];
        if (y2 < n)
            udlr[1] = sum[y2 + 1][x2] - sum[y2 + 1][x1 - 1] - sum[y2][x2] + sum[y2][x1 - 1];
        if (x1 > 1)
            udlr[2] = sum[y2][x1 - 1] - sum[y1 - 1][x1 - 1] - sum[y2][x1 - 2] + sum[y1 - 1][x1 - 2];
        if (x2 < n)
            udlr[3] = sum[y2][x2 + 1] - sum[y1 - 1][x2 + 1] - sum[y2][x2] + sum[y1 - 1][x2];
        auto it = max_element(udlr.begin(), udlr.end());
        if (*it <= 0)
            break;
        int idx = it - udlr.begin();
        if (idx == 0) {
            y1--;
            route += 'U';
            ans += *it;
        } else if (idx == 1) {
            y2++;
            route += 'D';
            ans += *it;
        } else if (idx == 2) {
            x1--;
            route += 'L';
            ans += *it;
        } else if (idx == 3) {
            x2++;
            route += 'R';
            ans += *it;
        }
    }
    cout << ans << route;
}