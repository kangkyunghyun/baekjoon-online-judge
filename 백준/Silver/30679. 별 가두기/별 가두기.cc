#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m, a[100][100];
    vector<int> ans;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        int visited[100][100][4] = {0};
        int x = i, y = 0, d = 0;
        while (1) {
            int v = a[x][y];
            visited[x][y][d] = 1;
            if (d == 0)
                y += v;
            else if (d == 1)
                x += v;
            else if (d == 2)
                y -= v;
            else
                x -= v;
            d = (d + 1) % 4;
            if (x < 0 || y < 0 || x >= n || y >= m)
                break;
            if (visited[x][y][d]) {
                ans.push_back(i + 1);
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
}