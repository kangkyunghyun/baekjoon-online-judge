#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    int winSize = 0, ans = s.size();
    for (char c : s)
        if (c == 'a')
            winSize++;
    for (int i = 0; i < s.size(); i++) {
        int cnt = 0;
        for (int j = i; j < i + winSize; j++)
            if (s[j % s.size()] == 'b')
                cnt++;
        ans = min(ans, cnt);
    }
    cout << ans;
}