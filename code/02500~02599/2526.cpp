#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, p, cnt = 1;
    cin >> n >> p;
    vector<int> v(max(n + 1, p + 1), 0);
    v[n] = cnt++;
    int x = n;
    while (1) {
        x = (x * n) % p;
        if (v[x]) {
            cout << cnt - v[x];
            return 0;
        }
        v[x] = cnt++;
    }
}