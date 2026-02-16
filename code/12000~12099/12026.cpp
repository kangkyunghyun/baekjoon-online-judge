#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 987654321

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, curr = 0;
    string s;
    cin >> n >> s;
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((s[i] == 'B' && s[j] == 'O') || (s[i] == 'O' && s[j] == 'J') || (s[i] == 'J' && s[j] == 'B'))
                dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
    cout << (dp[n - 1] == INF ? -1 : dp[n - 1]);
}