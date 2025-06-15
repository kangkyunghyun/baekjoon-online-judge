#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int visited[10][9] = {0}, dx[] = {3, 3, -3, -3, 2, 2, -2, -2}, dy[] = {2, -2, 2, -2, 3, -3, 3, -3};
    pair<int, int> check[][2] = {{{1, 0}, {2, 1}}, {{1, 0}, {2, -1}}, {{-1, 0}, {-2, 1}}, {{-1, 0}, {-2, -1}}, {{0, 1}, {1, 2}}, {{0, -1}, {1, -2}}, {{0, 1}, {-1, 2}}, {{0, -1}, {-1, -2}}};
    queue<pair<int, int>> q;
    q.push({r1, c1});
    visited[r1][c1] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i], flag = 0;
            if (nx < 0 || ny < 0 || nx > 9 || ny > 8)
                continue;
            for (int j = 0; j < 2; j++)
                if (x + check[i][j].first == r2 && y + check[i][j].second == c2)
                    flag = 1;
            if (flag)
                continue;
            if (!visited[nx][ny]) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << visited[r2][c2] - 1;
}