#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    vector<int> ans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < t[i]; j++)
            ans.push_back(i + 1);
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}