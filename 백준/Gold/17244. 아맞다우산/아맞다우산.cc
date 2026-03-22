#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, cnt = 0;
int arr[50][50], visited[50][50][32], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
queue<vector<int>> q;

signed main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                arr[i][j] = ++cnt;
            } else if (c == '#') {
                arr[i][j] = -1;
            } else if (c == 'E') {
                arr[i][j] = 6;
            } else if (c == 'S') {
                arr[i][j] = 0;
                q.push({i, j, 0});
                visited[i][j][0] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front()[0], y = q.front()[1], b = q.front()[2];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (arr[nx][ny] < 0)
                continue;
            if (b == ((1 << cnt) - 1) && arr[nx][ny] == 6) {
                cout << visited[x][y][b];
                return 0;
            }
            if (arr[nx][ny] > 0) {
                int nb = b | (1 << (arr[nx][ny] - 1));
                if (!visited[nx][ny][nb]) {
                    visited[nx][ny][nb] = visited[x][y][b] + 1;
                    q.push({nx, ny, nb});
                }
            }
            if (!visited[nx][ny][b]) {
                visited[nx][ny][b] = visited[x][y][b] + 1;
                q.push({nx, ny, b});
            }
        }
    }
}