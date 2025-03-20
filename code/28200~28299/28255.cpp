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
        string sp = s.substr(0, (s.size() + 2) / 3);
        string rev = sp;
        reverse(rev.begin(), rev.end());
        string tail = sp.substr(1, sp.size() - 1);
        string tailRev = rev.substr(1, rev.size() - 1);
        cout << (s == sp + rev + sp || s == sp + tailRev + sp || s == sp + rev + tail || s == sp + tailRev + tail) << '\n';
    }
}