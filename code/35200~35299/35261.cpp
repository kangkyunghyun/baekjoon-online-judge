#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 100;
    string s, t = "eagle";
    cin >> n >> s;
    for (int i = 0; i < n - 4; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++)
            if (s[i + j] != t[j])
                cnt++;
        ans = min(ans, cnt);
    }
    cout << ans;
}