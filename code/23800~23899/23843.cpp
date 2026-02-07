#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for (int &i : t)
        cin >> i;
    sort(t.begin(), t.end(), greater<>());
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < m; i++)
        pq.push(0);
    for (int i : t) {
        int x = pq.top() + i;
        pq.pop();
        pq.push(x);
    }
    int ans = 0;
    while (!pq.empty()) {
        ans = max(ans, pq.top());
        pq.pop();
    }
    cout << ans;
}