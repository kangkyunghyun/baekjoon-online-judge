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
        vector<int> h(n);
        for (int &i : h)
            cin >> i;
        int left = h[k - 1];
        sort(h.begin(), h.end());
        int idx = lower_bound(h.begin(), h.end(), left) - h.begin();
        string ans = "YES";
        for (int i = idx + 1; i < n; i++) {
            int gap = h[i] - h[i - 1];
            if (gap > left) {
                ans = "NO";
                break;
            }
        }
        cout << ans << '
';
    }
}