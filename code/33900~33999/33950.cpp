#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && s[i] == 'P' && s[i + 1] == 'O') {
                cout << "PHO";
                i++;
            } else
                cout << s[i];
        }
        cout << '\n';
    }
}