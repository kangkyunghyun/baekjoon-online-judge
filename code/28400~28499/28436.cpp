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
        reverse(s.begin(), s.end());
        char curr = '.';
        int move = 0, cnt = 0;
        for (char c : s) {
            if (curr == '.')
                curr = c;
            if (curr == '.')
                continue;
            if (c == '.')
                move += (curr == 'W' ? cnt : -cnt);
            else if (c == curr)
                cnt++;
            else
                curr = '.', cnt = 0;
        }
        cout << (move > 0 ? "WHITE" : "BLACK") << '\n';
    }
}