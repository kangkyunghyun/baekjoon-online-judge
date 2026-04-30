#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0;
        string s;
        cin >> n >> s;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt++;
                ans.push_back(i + 1);
            }
        }
        cout << cnt << '
';
        for (int i : ans)
            cout << i << ' ';
        cout << '
';
    }
}