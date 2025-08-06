#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s, origin;
        cin >> s;
        origin = s;
        int flag = 0;
        do {
            if (flag++ == 1) {
                cout << s << '\n';
                break;
            }
        } while (next_permutation(s.begin(), s.end()));
        if (flag == 1)
            cout << origin << '\n';
    }
}