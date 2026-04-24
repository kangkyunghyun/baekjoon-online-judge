#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int ans = 10;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
        ans += (s[i] == s[i - 1] ? 5 : 10);
    cout << ans;
}