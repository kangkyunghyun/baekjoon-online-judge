#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (1) {
        ans++;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[i] < a[j])
                    cnt++;
            }
            b[i] = cnt;
        }
        if (a == b)
            break;
        a = b;
    }
    cout << ans;
}