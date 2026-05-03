#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        string t = s;
        sort(t.begin(), t.end());
        if (s == t) {
            cout << "Bob
";
        } else {
            vector<int> ans;
            for (int i = 0; i < n; i++)
                if (s[i] != t[i])
                    ans.push_back(i + 1);
            cout << "Alice
"
                 << ans.size() << '
';
            for (int i : ans)
                cout << i << ' ';
            cout << '
';
        }
    }
}