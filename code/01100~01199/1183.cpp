#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = b - a;
    }
    if (n % 2 == 1) {
        cout << 1;
        return 0;
    }
    sort(v.begin(), v.end());
    cout << v[n / 2] - v[n / 2 - 1] + 1;
}