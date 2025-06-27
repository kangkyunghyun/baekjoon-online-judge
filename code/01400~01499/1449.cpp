#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, l, ans = 1;
    cin >> n >> l;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int start = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] - start + 1 > l) {
            ans++;
            start = v[i];
        }
    cout << ans;
}