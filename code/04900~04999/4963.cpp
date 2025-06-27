#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    while (1) {
        int w, h, ans = 0;
        cin >> w >> h;
        if (w + h == 0)
            break;
        int arr[50][50] = {0}, visited[50][50] = {0}, dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin >> arr[i][j];
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if (!visited[i][j] && arr[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = ++ans;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int a = 0; a < 8; ++a) {
                            int nx = x + dx[a];
                            int ny = y + dy[a];
                            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                                continue;
                            if (!visited[nx][ny] && arr[nx][ny]) {
                                q.push({nx, ny});
                                visited[nx][ny] = ans;
                            }
                        }
                    }
                }
        cout << ans << '\n';
    }
}