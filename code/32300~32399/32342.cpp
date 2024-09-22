#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        int ans = 0;
        if (s.size() < 3) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 0; i < s.size()-2; i++)
            if (s[i] == 'W' && s[i+1] == 'O' && s[i+2] == 'W')
                ans++;
        cout << ans << '\n';
    }
}