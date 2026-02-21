#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, dx[] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[] = {1, -1, 0, 0, 1, -1, 1, -1}, ans = 0;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                int nnx = i + dx[k] * 2, nny = j + dy[k] * 2;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || nnx < 0 || nnx >= n || nny < 0 || nny >= m)
                    continue;
                if (v[i][j] == 'F' && v[nx][ny] == 'O' && v[nnx][nny] == 'X')
                    ans++;
            }
        }
    }
    cout << ans;
}