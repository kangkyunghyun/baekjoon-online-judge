#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int ans = 0;
    vector<int> v(11, 0);
    for (int i = 1; i <= 10; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    for (int i = 1; i <= 10; i++)
        if (abs(v[i] - 100) <= abs(ans - 100))
            ans = v[i];
    cout << ans;
}