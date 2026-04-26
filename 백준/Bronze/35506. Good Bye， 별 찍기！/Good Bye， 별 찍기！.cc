#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int rows = 2 * n;
    int cols = 4 * n + 2;
    for (int i = 0; i < rows; i++) {
        string s(cols, ' ');
        s[2 * n - 1 - i] = '*';
        s[i < n ? 3 * n - i : n + 1 + i] = '*';
        s[i < n ? 3 * n + 2 + i : 5 * n + 1 - i] = '*';
        cout << s << '\n';
    }
}