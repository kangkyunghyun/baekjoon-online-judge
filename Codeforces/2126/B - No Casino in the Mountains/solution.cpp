#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n), len;
        int size = 0;
        for (int &i : v) {
            cin >> i;
            if (i == 1) {
                if (size == 0)
                    continue;
                len.push_back(size);
                size = 0;
            } else {
                size++;
            }
        }
        if (size)
            len.push_back(size);
        if (len.size() == 0) {
            cout << "0
";
            continue;
        }
        int ans = 0;
        for (int i : len) {
            for (int j = 0; j < i; j++) {
                if (j + k <= i) {
                    j += k;
                    ans++;
                } else {
                    break;
                }
            }
        }
        cout << ans << '
';
    }
}