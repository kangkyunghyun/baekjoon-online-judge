#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, p, ans = 0;
    cin >> n >> p;
    vector<priority_queue<int>> pq(n + 1);
    while (n--) {
        int l, f;
        cin >> l >> f;
        while (!pq[l].empty() && pq[l].top() > f) {
            pq[l].pop();
            ans++;
        }
        if (!pq[l].empty() && pq[l].top() == f)
            continue;
        pq[l].push(f);
        ans++;
    }
    cout << ans;
}