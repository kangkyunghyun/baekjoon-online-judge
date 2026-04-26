#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n && n != 0) {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int m = 0;
        for (int i = 2; i < n; i++)
            m = max(m, a[i] + a[i - 1] + a[i - 2]);
        cout << m << '\n';
    }
}