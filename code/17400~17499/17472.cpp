#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, graph[10][10], visited[10][10], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, cnt = 0, ans = 0, sum = 0;
queue<pair<int, int>> q;
vector<vector<pair<int, int>>> islands;
vector<pair<int, pair<int, int>>> edge;
vector<int> p;

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x < y)
        p[y] = x;
    else
        p[x] = y;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                vector<pair<int, int>> tmp;
                q.push({i, j});
                visited[i][j] = ++cnt;
                tmp.push_back({i, j});
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (!visited[nx][ny] && graph[nx][ny]) {
                            q.push({nx, ny});
                            visited[nx][ny] = visited[x][y];
                            tmp.push_back({nx, ny});
                        }
                    }
                }
                islands.push_back(tmp);
            }
        }
    for (int i = 0; i < islands.size(); i++) {
        vector<pair<int, int>> island = islands[i];
        for (auto [x, y] : island) {
            for (int j = 0; j < 4; j++) {
                int tmpX = dx[j], tmpY = dy[j], len = 0;
                while (x + tmpX >= 0 && x + tmpX < n && y + tmpY >= 0 && y + tmpY < m) {
                    if (visited[x + tmpX][y + tmpY] == visited[x][y])
                        break;
                    else if (visited[x + tmpX][y + tmpY] != 0) {
                        if (len > 1)
                            edge.push_back({len, {visited[x + tmpX][y + tmpY], visited[x][y]}});
                        break;
                    } else
                        len++;
                    if (tmpX < 0)
                        tmpX--;
                    else if (tmpX > 0)
                        tmpX++;
                    else if (tmpY < 0)
                        tmpY--;
                    else if (tmpY > 0)
                        tmpY++;
                }
            }
        }
    }
    p.resize(cnt + 1);
    iota(p.begin(), p.end(), 0);
    sort(edge.begin(), edge.end());
    for (auto [weigh, path] : edge)
        if (find(path.first) != find(path.second)) {
            ans += weigh;
            merge(path.first, path.second);
        }
    for (int i = 1; i <= cnt; i++)
        sum += find(i);
    cout << (sum != cnt ? -1 : ans);
}