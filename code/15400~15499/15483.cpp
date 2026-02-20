#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    int dp[1001][1001] = {0};
    for (int i = 0; i <= max(a.size(), b.size()); i++)
        dp[0][i] = dp[i][0] = i;
    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
            dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] : min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
    cout << dp[a.size()][b.size()];
}