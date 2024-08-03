#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n - 2; i++) {
        if (i == n - 3) {
            v[0]--;
            v[n - 1]--;
        } else {
            if (v[0] > v[n - 1])
                v[0]--;
            else
                v[n - 1]--;
        }
    }
    cout << max(v[0], v[n - 1]);
}