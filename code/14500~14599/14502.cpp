#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, ans = 0, tmp = 100;
int arr[8][8] = {0}, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
vector<pair<int, int>> virus;

int bfs() {
    int visited[8][8] = {0}, cnt = 0;
    queue<pair<int, int>> q;
    for (auto [a, b] : virus) {
        visited[a][b] = 1;
        q.push({a, b});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (!visited[nx][ny] && !arr[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (!arr[i][j])
                ans++;
            if (arr[i][j] == 2)
                virus.push_back({i, j});
        }
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            for (int i2 = 0; i2 < n; i2++)
                for (int j2 = 0; j2 < m; j2++)
                    for (int i3 = 0; i3 < n; i3++)
                        for (int j3 = 0; j3 < m; j3++) {
                            if ((i1 == i2 && j1 == j2) || (i1 == i3 && j1 == j3) || (i3 == i2 && j3 == j2))
                                continue;
                            if (arr[i1][j1] || arr[i2][j2] || arr[i3][j3])
                                continue;
                            arr[i1][j1] = arr[i2][j2] = arr[i3][j3] = 1;
                            tmp = min(tmp, bfs());
                            arr[i1][j1] = arr[i2][j2] = arr[i3][j3] = 0;
                        }
    cout << ans - tmp - 3;
}