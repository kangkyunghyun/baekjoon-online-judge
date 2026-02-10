#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Data {
    int x, y, z;
};

int n, m, k;
int visited[1001][1001][11];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
queue<Data> q;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    visited[0][0][0] = 1;
    q.push({0, 0, 0});
    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1) {
            cout << visited[x][y][z];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (v[nx][ny] == '1' && !visited[nx][ny][z + 1] && z < k) {
                visited[nx][ny][z + 1] = visited[x][y][z] + 1;
                q.push({nx, ny, z + 1});
            } else if (v[nx][ny] == '0' && !visited[nx][ny][z]) {
                visited[nx][ny][z] = visited[x][y][z] + 1;
                q.push({nx, ny, z});
            }
        }
    }
    cout << -1;
}