#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        int flag = 0;
        for (int l = 1; l < n - 1; l++) {
            if (flag)
                break;
            for (int r = l + 1; r < n; r++) {
                int s1 = a[l] % 3;
                int s2 = (a[r] - a[l]) % 3;
                int s3 = (a[n] - a[r]) % 3;
                if ((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s1 != s3)) {
                    cout << l << ' ' << r << '
';
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
            cout << "0 0
";
    }
}