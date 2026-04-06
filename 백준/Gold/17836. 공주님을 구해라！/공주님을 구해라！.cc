#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, t, arr[100][100], visited[100][100][2], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, ans = 1e9;
queue<vector<int>> q;

signed main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    q.push({0, 0, 0});
    visited[0][0][0] = 1;
    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();
        int x = v[0], y = v[1], g = v[2];
        if (x == n - 1 && y == m - 1)
            ans = min(ans, visited[x][y][g] - 1);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (g == 0) {
                if (arr[nx][ny] == 0 && !visited[nx][ny][0]) {
                    visited[nx][ny][0] = visited[x][y][0] + 1;
                    q.push({nx, ny, 0});
                } else if (arr[nx][ny] == 2 && !visited[nx][ny][1]) {
                    visited[nx][ny][1] = visited[x][y][0] + 1;
                    q.push({nx, ny, 1});
                }
            } else {
                if (!visited[nx][ny][1]) {
                    visited[nx][ny][1] = visited[x][y][1] + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }
    if (ans <= t)
        cout << ans;
    else
        cout << "Fail";
}