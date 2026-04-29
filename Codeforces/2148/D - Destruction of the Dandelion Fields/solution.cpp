#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        vector<int> odd;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            if (x % 2)
                odd.push_back(x);
        }
        if (odd.size() == 0) {
            cout << 0 << '
';
            continue;
        }
        if (odd.size() == 1) {
            cout << sum << '
';
            continue;
        }
        sort(odd.begin(), odd.end());
        for (int i = 0; i < odd.size() / 2; i++)
            sum -= odd[i];
        cout << sum << '
';
    }
}