#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c, n;
    cin >> r >> c >> n;
    int arr[200][200] = {0}, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            arr[i][j] = (s[j] == '.' ? -2 : 0);
    }
    while (n--) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                arr[i][j]++;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == 3) {
                    arr[i][j] = -1;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 0 || y < 0 || x >= r || y >= c)
                            continue;
                        if (arr[x][y] == 3)
                            continue;
                        arr[x][y] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << (arr[i][j] < 0 ? '.' : 'O');
        cout << '\n';
    }
}