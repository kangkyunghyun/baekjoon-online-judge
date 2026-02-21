#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    cin >> t;
    while (t--) {
        vector<string> v(3);
        for (auto &i : v)
            cin >> i;
        int n;
        cin >> n;
        vector<int> ans, a(n);
        for (int &i : a)
            cin >> i;
        int visited[3][3] = {0};
        queue<pair<int, int>> q;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (v[i][j] == 'O' && !visited[i][j]) {
                    int cnt = 1;
                    visited[i][j] = 1;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int nx = x + dx[i], ny = y + dy[i];
                            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3)
                                continue;
                            if (v[nx][ny] == 'O' && !visited[nx][ny]) {
                                cnt++;
                                visited[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                    ans.push_back(cnt);
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << (a == ans) << '\n';
    }
}