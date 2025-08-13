#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 1e9, h = n / 60, d[] = {60, 10, -10, 1, -1};
        n %= 60;
        if (n == 0) {
            cout << h << " 0 0 0 0\n";
            continue;
        }
        vector<pair<int, vector<int>>> visited(61, {-1, vector<int>(5, 0)});
        queue<int> q;
        visited[0].first = 0;
        visited[0].second[0] = h;
        q.push(0);
        vector<vector<int>> ans;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < 5; i++) {
                int next = curr + d[i];
                if (next < 0 || next > 60)
                    continue;
                if (visited[next].first == -1 || next == n) {
                    visited[next].first = visited[curr].first + 1;
                    visited[next].second = visited[curr].second;
                    visited[next].second[i]++;
                    if (next == n && visited[next].first <= cnt) {
                        cnt = visited[next].first;
                        ans.push_back(visited[next].second);
                    } else
                        q.push(next);
                }
            }
        }
        sort(ans.begin(), ans.end());
        for (int i : ans[0])
            cout << i << ' ';
        cout << '\n';
    }
}