#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int t = 0; t < 4; t++) {
        int x1, y1, p1, q1, x2, y2, p2, q2;
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;
        if (p1 < x2 || p2 < x1 || q1 < y2 || q2 < y1)
            cout << 'd';
        else if ((p1 == x2 && q1 == y2) || (x1 == p2 && y1 == q2) || (p1 == x2 && y1 == q2) || (x1 == p2 && q1 == y2))
            cout << 'c';
        else if (p1 == x2 || p2 == x1 || y1 == q2 || y2 == q1)
            cout << 'b';
        else
            cout << 'a';
        cout << '\n';
    }
}