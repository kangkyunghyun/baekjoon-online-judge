#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int arr[1001][1001];
int dp[1001][1001];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-1], dp[i][j-1]))+arr[i][j];
    cout << dp[n][m];
}