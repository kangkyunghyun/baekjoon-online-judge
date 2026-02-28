#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, cnt = 0;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int visited[301][301];
vector<string> v;
queue<pair<int, int>> q1, q2;

void jump(int cnt) {
    if (cnt % 2) {
        while (!q1.empty()) {
            auto [x, y] = q1.front();
            q1.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (!visited[nx][ny]) {
                    if (v[nx][ny] == '0')
                        q1.push({nx, ny});
                    else
                        q2.push({nx, ny});
                    visited[nx][ny] = cnt;
                }
            }
        }
    } else {
        while (!q2.empty()) {
            auto [x, y] = q2.front();
            q2.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (!visited[nx][ny]) {
                    if (v[nx][ny] == '0')
                        q2.push({nx, ny});
                    else
                        q1.push({nx, ny});
                    visited[nx][ny] = cnt;
                }
            }
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    q1.push({x1 - 1, y1 - 1});
    while (!visited[x2 - 1][y2 - 1]) {
        jump(++cnt);
        if (visited[x2 - 1][y2 - 1])
            break;
        jump(++cnt);
    }
    cout << cnt;
}