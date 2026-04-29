#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0, ans = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                cnt++;
        for (int i = 0; i < cnt; i++)
            if (s[i] == '1')
                ans++;
        cout << ans << '
';
    }
}