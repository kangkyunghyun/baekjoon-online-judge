#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n), d(n - 1);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
        d[i] = v[i + 1] - v[i];
    sort(d.begin(), d.end());
    if (n - k > 0)
        cout << accumulate(d.begin(), d.end() - k + 1, 0);
    else
        cout << 0;
}