#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<string> s(8);
    for (int i = 0; i < 8; i++)
        cin >> s[i];
    int ans = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if ((i + j) % 2 == 0 && s[i][j] == 'F')
                ans++;
    cout << ans;
}