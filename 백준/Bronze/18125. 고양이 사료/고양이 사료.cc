#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string ans = "|>___/|        /}\n| O < |       / }\n(==0==)------/ }\n| ^  _____    |\n|_|_/     ||__|";
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    for (int j = c - 1; j >= 0; j--)
        for (int i = 0; i < r; i++)
            cin >> a[i][j];
    for (int i = 0; i < r; i++) {
        for (int j = 0, x; j < c; j++) {
            cin >> x;
            if (a[i][j] != x)
                ans = "|>___/|     /}\n| O O |    / }\n( =0= )\"\"\"\"  \\\n| ^  ____    |\n|_|_/    ||__|";
        }
    }
    cout << ans;
}