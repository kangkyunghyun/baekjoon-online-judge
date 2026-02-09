#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        v[i] = {100 * m1 + d1, 100 * m2 + d2};
    }
    sort(v.begin(), v.end());
    int cnt = 1, currEnd = 301, maxEnd = 301;
    for (auto [start, end] : v) {
        if (maxEnd >= 1201)
            break;
        if (start > currEnd) {
            currEnd = maxEnd;
            cnt++;
        }
        if (start > currEnd)
            break;
        maxEnd = max(maxEnd, end);
    }
    cout << (maxEnd < 1201 ? 0 : cnt);
}