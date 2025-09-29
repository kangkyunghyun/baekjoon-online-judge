#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<pair<int, int>> v(3);
    for (int i = 0; i < 3; i++)
        cin >> v[i].first >> v[i].second;
    int n = min({v[0].first, v[1].second, v[2].first});
    int m = min({v[0].second, v[1].first, v[2].second});
    int ans = 0;
    if (n == m)
        ans = n + m;
    else if (n > m)
        ans = 2 * m + 1;
    else
        ans = 2 * n + 1;
    cout << ans << "\n";
}