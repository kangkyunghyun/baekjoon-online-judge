#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            if (c[i] % 2)
                c[i]++;
        }
        while (1) {
            bool check = true;
            for (int i = 1; i < n; i++)
                if (c[i] != c[0]) {
                    check = false;
                    break;
                }
            if (check)
                break;
            vector<int> tmp(n);
            for (int i = 0; i < n; i++)
                if (i == n-1) {
                    tmp[0] += c[i] / 2;
                    c[n - 1] -= c[n - 1] / 2;
                } else {
                    tmp[i + 1] += c[i] / 2;
                    c[i] -= c[i] / 2;
                }   
            for (int i = 0; i < n; i++)
                c[i] += tmp[i];
            for (int i = 0; i < n; i++)
                if (c[i] % 2)
                    c[i]++;
            ans++;
        }
        cout << ans << '\n';
    }
}