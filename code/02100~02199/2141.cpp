#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, sum = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[a, b] : v) {
        cin >> a >> b;
        sum += b;
    }
    sort(v.begin(), v.end());
    int tmp = 0;
    for (auto [a, b] : v) {
        tmp += b;
        if (2 * tmp >= sum) {
            cout << a;
            break;
        }
    }
}