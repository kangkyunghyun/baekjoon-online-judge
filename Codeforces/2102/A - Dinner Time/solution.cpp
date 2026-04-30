#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        if (n % p == 0 && (n / p) * q != m)
            cout << "NO
";
        else
            cout << "YES
";
    }
}