#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    vector<int> dp(40, 1);
    for (int i = 1; i < s.size(); i++) {
        int n = stoi(s.substr(i - 1, 2));
        if (s[i] == '0') {
            if (i == 1)
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 2];
        } else if (n >= 11 && n <= 34) {
            if (i == 1)
                dp[i] = 2;
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        } else
            dp[i] = dp[i - 1];
    }
    cout << dp[s.size() - 1];
}