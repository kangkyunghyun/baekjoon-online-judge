#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, flag = 0;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n && !flag; i++) {
            if (p[i] == n - i)
                continue;
            for (int j = i + 1; j < n && !flag; j++)
                if (p[j] == n - i) {
                    swap(p[i], p[j]);
                    flag = 1;
                }
        }
        for (int i : p)
            cout << i << ' ';
        cout << '
';
    }
}