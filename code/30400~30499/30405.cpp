#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    while (n--) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            if (i == 0 || i == k - 1)
                v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    cout << v[(v.size() - 1) / 2];
}