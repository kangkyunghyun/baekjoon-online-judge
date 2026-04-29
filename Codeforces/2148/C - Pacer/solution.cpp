#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        int flag = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            if (i == 0) {
                if (a[i] % 2 != b[i] % 2) {
                    m--;
                    flag = !flag;
                }
            } else {
                if (flag) {
                    if (a[i] % 2 == b[i] % 2) {
                        m--;
                        flag = !flag;
                    }
                } else {
                    if (a[i] % 2 != b[i] % 2) {
                        m--;
                        flag = !flag;
                    }
                }
            }
        }
        cout << m << '
';
    }
}