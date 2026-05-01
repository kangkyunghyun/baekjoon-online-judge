#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int k, x;
        cin >> k >> x;
        int target = 1LL << k;
        int total_cakes = 1LL << (k + 1);
        vector<int> ans;
        while (x != target) {
            if (x < target) {
                ans.push_back(1);
                x *= 2;
            } else {
                ans.push_back(2);
                x = 2 * x - total_cakes;
            }
        }
        cout << ans.size() << '
';
        reverse(ans.begin(), ans.end());
        for (int i : ans)
            cout << i << ' ';
        cout << '
';
    }
}