#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int m, ans = 0;
        cin >> m;
        set<int> left, right;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            left.insert(x);
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            right.insert(x);
        }
        for (auto it = left.begin(); it != left.end(); it++) {
            int curr = *it;
            if (left.find(curr + 500) != left.end() && right.find(curr + 1000) != right.end() && right.find(curr + 1500) != right.end())
                ans++;
        }
        cout << ans << '\n';
    }
}