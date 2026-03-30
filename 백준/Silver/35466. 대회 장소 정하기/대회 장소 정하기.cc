#include <bits/stdc++.h>
using namespace std;
#define int long long

int dist(int x, int y, int n) {
    return min(abs(x - y), n - abs(x - y));
}

signed main() {
    int n, a, b, c, p, q;
    cin >> n >> a >> b >> c >> p >> q;
    int U = 0, D = -1, P = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (dist(U, i, n) == a && dist(i, j, n) == b && dist(j, U, n) == c) {
                D = i, P = j;
                break;
            }
        if (D != -1)
            break;
    }
    for (int i = 0; i < n; i++)
        if (dist(i, U, n) == p && dist(i, D, n) == q) {
            cout << dist(i, P, n);
            break;
        }
}