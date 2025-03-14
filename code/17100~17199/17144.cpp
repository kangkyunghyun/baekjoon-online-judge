#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c, t;
    cin >> r >> c >> t;
    int cleaner[2], arr[51][51] = {0}, add[51][51] = {0}, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    int flag = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                if (!flag) {
                    cleaner[0] = i;
                    flag = 1;
                } else {
                    cleaner[1] = i;
                }
            }
        }
    }
    while (t--) {
        for (int x = 0; x < r; x++)
            for (int y = 0; y < c; y++) {
                if (arr[x][y] <= 0)
                    continue;
                int cnt = 0;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= r || ny >= c)
                        continue;
                    if (arr[nx][ny] == -1)
                        continue;
                    add[nx][ny] += arr[x][y] / 5;
                    cnt++;
                }
                add[x][y] -= arr[x][y] / 5 * cnt;
            }
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                arr[i][j] += add[i][j];
                add[i][j] = 0;
            }
        for (int i = cleaner[0] - 1; i > 0; i--)
            arr[i][0] = arr[i - 1][0];
        for (int i = 0; i < c - 1; i++)
            arr[0][i] = arr[0][i + 1];
        for (int i = 0; i < cleaner[0]; i++)
            arr[i][c - 1] = arr[i + 1][c - 1];
        for (int i = c - 1; i > 1; i--)
            arr[cleaner[0]][i] = arr[cleaner[0]][i - 1];
        arr[cleaner[0]][1] = 0;
        for (int i = cleaner[1] + 1; i < r - 1; i++)
            arr[i][0] = arr[i + 1][0];
        for (int i = 0; i < c - 1; i++)
            arr[r - 1][i] = arr[r - 1][i + 1];
        for (int i = r - 1; i > cleaner[1]; i--)
            arr[i][c - 1] = arr[i - 1][c - 1];
        for (int i = c - 1; i > 1; i--)
            arr[cleaner[1]][i] = arr[cleaner[1]][i - 1];
        arr[cleaner[1]][1] = 0;
    }
    int ans = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == -1)
                continue;
            ans += arr[i][j];
        }
    cout << ans;
}