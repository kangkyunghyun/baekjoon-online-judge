#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << ((x - 2 * y) % 3 == 0 && (x - 2 * y) >= 0 && (x + 4 * y) >= 0 ? "YES
" : "NO
");
    }
}