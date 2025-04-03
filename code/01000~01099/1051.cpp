#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int small = min(n, m);
    for (int size = small; size >= 1; size--) {
        for (int i = 0; i <= n - size; i++) {
            for (int j = 0; j <= m - size; j++) {
                char a = v[i][j];
                char b = v[i][j + size - 1];
                char c = v[i + size - 1][j];
                char d = v[i + size - 1][j + size - 1];
                if (a == b && b == c && c == d) {
                    cout << size * size;
                    return 0;
                }
            }
        }
    }
}