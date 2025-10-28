#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 10)
            b.push_back(x);
        else
            a.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.insert(a.end(), b.begin(), b.end());
    for (int i = 0; i < n && m; i++) {
        int tmp = a[i];
        if (tmp == 10) {
            ans++;
            continue;
        }
        while (tmp > 10 && m) {
            tmp -= 10;
            ans++;
            m--;
        }
        if (tmp == 10)
            ans++;
    }
    cout << ans;
}