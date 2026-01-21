#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                cnt++;
                if (cnt == k) {
                    cout << min(a[j], a[j + 1]) << ' ' << max(a[j], a[j + 1]);
                    return 0;
                }
            }
        }
    }
    cout << -1;
}