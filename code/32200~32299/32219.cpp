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
            cout << min(r, c) << ' ' << min(r, c) << '\n';
        }
    }
}