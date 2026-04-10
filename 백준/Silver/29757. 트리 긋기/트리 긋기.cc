#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i + 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
        cout << v[i][2] << ' ' << v[i + 1][2] << '\n';
}