#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int c;
    cin >> c;
    stack<pair<int, int>> s;
    vector<int> ans;
    while (c--) {
        int m;
        cin >> m;
        if (s.empty()) {
            if (m == 1) {
                s.push({m, 1});
                ans.push_back(1);
                continue;
            } else {
                cout << -1;
                return 0;
            }
        }
        if (s.top().first + 1 == m) {
            s.push({m, 1});
            ans.push_back(1);
        } else if (s.top().first == m) {
            auto [a, b] = s.top();
            s.pop();
            s.push({a, b + 1});
            ans.push_back(b + 1);
        } else if (s.top().first > m) {
            while (s.top().first > m)
                s.pop();
            if (s.top().first + 1 == m) {
                s.push({m, 1});
                ans.push_back(1);
            } else if (s.top().first == m) {
                auto [a, b] = s.top();
                s.pop();
                s.push({a, b + 1});
                ans.push_back(b + 1);
            } else {
                cout << -1;
                return 0;
            }
        } else {
            cout << -1;
            return 0;
        }
    }
    for (int i : ans)
        cout << i << ' ';
}