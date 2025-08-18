#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, a[100][100], now[100];
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            now[j] += a[j][i];
            if (now[j] >= k) {
                cout << j + 1 << ' ' << i + 1;
                return 0;
            }
        }
}