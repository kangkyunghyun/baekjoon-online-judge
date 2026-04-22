#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p1 = 0, p2 = 0;
        cin >> n;
        while (n--) {
            char a, b;
            cin >> a >> b;
            if (a == b)
                continue;
            if (a == 'R') {
                if (b == 'S')
                    p1++;
                else
                    p2++;
            } else if (a == 'P') {
                if (b == 'R')
                    p1++;
                else
                    p2++;
            } else {
                if (b == 'P')
                    p1++;
                else
                    p2++;
            }
        }
        string ans = "TIE";
        if (p1 > p2)
            ans = "Player 1";
        else if (p1 < p2)
            ans = "Player 2";
        cout << ans << '\n';
    }
}