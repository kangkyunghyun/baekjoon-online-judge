#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> rotate(vector<vector<int>> v, int n) {
    vector<vector<int>> ret{v};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                ret[i][n / 2] = v[i][j];
            else if (j == n / 2)
                ret[i][n - i - 1] = v[i][j];
            else if (j == n - i - 1)
                ret[n / 2][j] = v[i][j];
            else if (i == n / 2)
                ret[j][j] = v[i][j];
            else
                ret[i][j] = v[i][j];
        }
    }
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        if (d < 0)
            d += 360;
        d /= 45;
        while (d--)
            v = rotate(v, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << v[i][j] << ' ';
            cout << '\n';
        }
    }
}