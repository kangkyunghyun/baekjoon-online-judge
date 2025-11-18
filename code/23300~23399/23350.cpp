#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, ans = 0;
    cin >> n >> m;
    queue<pair<int, int>> now;
    vector<int> priority;
    vector<pair<int, int>> stored;
    for (int i = 0; i < n; i++) {
        int p, w;
        cin >> p >> w;
        now.push({p, w});
        priority.push_back(p);
    }
    sort(priority.begin(), priority.end());
    while (!now.empty()) {
        auto [p, w] = now.front();
        now.pop();
        if (p == priority.back()) {
            priority.pop_back();
            vector<pair<int, int>> temp;
            while (!stored.empty() && stored.back().first == p && stored.back().second < w) {
                temp.push_back(stored.back());
                ans += stored.back().second;
                stored.pop_back();
            }
            stored.push_back({p, w});
            while (!temp.empty()) {
                stored.push_back(temp.back());
                ans += temp.back().second;
                temp.pop_back();
            }
        } else {
            now.push({p, w});
        }
        ans += w;
    }
    cout << ans;
}