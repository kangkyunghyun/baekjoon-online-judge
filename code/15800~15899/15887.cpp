#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> ans;
    for (int &i : v)
        cin >> i;
    for (int i = 0; i < n; i++) {
        if (v[i] != i + 1) {
            for (int j = i + 1; j < n; j++) {
                if (v[j] == i + 1) {
                    reverse(v.begin() + i, v.begin() + j + 1);
                    cnt++;
                    ans.push_back({i + 1, j + 1});
                }
            }
        }
    }
    cout << cnt << '\n';
    for (auto [i, j] : ans)
        cout << i << ' ' << j << '\n';
}