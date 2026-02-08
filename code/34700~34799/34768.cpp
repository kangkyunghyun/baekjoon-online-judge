#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0, k = 0; i < n; i += 2, k++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = j + k * n;
            if (j - 1 < 0)
                continue;
            v[i + 1][j - 1] = j + n * k;
        }
        v[i + 1][n - 1] = n * (k + 1);
    }
    v[0][0] = n * n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << ' ';
        cout << '\n';
    }
}