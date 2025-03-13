#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, jump;
    cin >> n >> m;
    int arr[101][101], visited[101][101];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cin >> jump;
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = -jump; i <= jump; i++)
            for (int j = -jump; j <= jump; j++) {
                if (abs(i) + abs(j) > jump)
                    continue;
                int nx = x + i;
                int ny = y + j;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (arr[nx][ny] == arr[0][0] && !visited[nx][ny]) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
    }
    cout << (visited[n - 1][m - 1] ? "ALIVE" : "DEAD");
}