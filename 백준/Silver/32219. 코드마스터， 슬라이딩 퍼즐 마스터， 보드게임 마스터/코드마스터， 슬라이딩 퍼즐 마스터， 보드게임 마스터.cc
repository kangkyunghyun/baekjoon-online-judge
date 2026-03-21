#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        if (r == c)
            cout << "dohoon\n";
        else {
            cout << "jinseo\n";
            if (r == 1)
                cout << r << ' ' << c - 1;
            else if (c == 1)
                cout << r - 1 << ' ' << c;
            else if (r == 2)
                cout << r << " 2";
            else if (c == 2)
                cout << "2 " << c;
            else
                cout << min(r, c) << ' ' << min(r, c);
            cout << '\n';
        }
    }
}