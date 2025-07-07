#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> v(2 * (n - 1)), s;
    for (int i = 0; i < 2 * (n - 1); i++) {
        cin >> v[i];
        if (v[i].size() == n - 1)
            s.push_back(v[i]);
    }
    vector<string> t{s[0][0] + s[1], s[1][0] + s[0]};
    for (int i = 0; i < 2; i++) {
        set<string> ss;
        string ans = "";
        for (int j = 0; j < 2 * (n - 1); j++) {
            if (t[i].find(v[j]) == 0) {
                if (ss.find(v[j]) == ss.end()) {
                    ans += 'P';
                    ss.insert(v[j]);
                } else {
                    ans += 'S';
                }
            } else if (t[i].find(v[j], t[i].size() - v[j].size()) == t[i].size() - v[j].size()) {
                ans += 'S';
            }
        }
        if (ans.size() == 2 * (n - 1)) {
            cout << t[i] << '\n'
                 << ans;
            break;
        }
    }
}