#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '*' && x + y == 0) {
                x = i + 1, y = j;
                cout << x + 1 << ' ' << y + 1 << '\n';
                break;
            }
        }
    }
    for (int i = 0; i < y; i++) {
        if (v[x][i] == '*') {
            cout << y - i << ' ';
            break;
        }
    }
    for (int i = n - 1; i > y; i--) {
        if (v[x][i] == '*') {
            cout << i - y << ' ';
            break;
        }
    }
    for (int i = n - 1; i > x; i--) {
        if (v[i][y] == '*') {
            cout << i - x << ' ';
            x = i;
            break;
        }
    }
    for (int i = n - 1; i > x; i--) {
        if (v[i][y - 1] == '*') {
            cout << i - x << ' ';
            break;
        }
    }
    for (int i = n - 1; i > x; i--) {
        if (v[i][y + 1] == '*') {
            cout << i - x << ' ';
            break;
        }
    }
}