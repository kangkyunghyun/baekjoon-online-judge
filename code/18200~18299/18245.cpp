#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int cnt = 2;
    while (1) {
        string s, ans = "";
        getline(cin, s);
        if (s == "Was it a cat I saw?")
            break;
        for (int i = 0; i < s.size(); i += cnt)
            ans += s[i];
        cout << ans << '\n';
        cnt++;
    }
}