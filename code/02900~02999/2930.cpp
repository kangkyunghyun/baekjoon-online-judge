#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, n, a = 0, b = 0;
    string s;
    cin >> r >> s >> n;
    vector<string> friends(n);
    for (string &f : friends)
        cin >> f;
    for (int i = 0; i < r; i++) {
        vector<int> cnt(3, 0);
        for (int j = 0; j < n; j++) {
            cnt[friends[j][i] == 'R' ? 0 : friends[j][i] == 'S' ? 1
                                                                : 2]++;
            if (s[i] == 'R') {
                if (friends[j][i] == 'S')
                    a += 2;
                else if (friends[j][i] == 'R')
                    a += 1;
            } else if (s[i] == 'S') {
                if (friends[j][i] == 'P')
                    a += 2;
                else if (friends[j][i] == 'S')
                    a += 1;
            } else {
                if (friends[j][i] == 'R')
                    a += 2;
                else if (friends[j][i] == 'P')
                    a += 1;
            }
        }
        int R = cnt[1] * 2 + cnt[0];
        int S = cnt[2] * 2 + cnt[1];
        int P = cnt[0] * 2 + cnt[2];
        b += max({R, S, P});
    }
    cout << a << '\n'
         << b;
}