#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 1;
    cin >> n;
    int arr[100][100] = {0}, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    for (int rain = 1; rain <= 100; ++rain) {
        int visited[100][100] = {0}, tmp = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (!visited[i][j] && arr[i][j] > rain) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = ++tmp;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int a = 0; a < 4; ++a) {
                            int nx = x + dx[a];
                            int ny = y + dy[a];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                                continue;
                            if (!visited[nx][ny] && arr[nx][ny] > rain) {
                                q.push({nx, ny});
                                visited[nx][ny] = tmp;
                            }
                        }
                    }
                }
        ans = max(ans, tmp);
    }
    cout << ans;
}