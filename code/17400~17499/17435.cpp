#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 19

int m, q, n, x, parent[500001][MAX];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> parent[i][0];
    for (int j = 1; j < MAX; j++)
        for (int i = 1; i <= m; i++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    cin >> q;
    while (q--) {
        cin >> n >> x;
        for (int i = MAX - 1; i >= 0; i--)
            if (n >= 1 << i) {
                n -= 1 << i;
                x = parent[x][i];
            }
        cout << x << '\n';
    }
}