#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 1;
        cin >> n;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pq.push(-x);
        }
        while (pq.size() >= 2) {
            int a = -pq.top() % 1000000007;
            pq.pop();
            int b = -pq.top() % 1000000007;
            pq.pop();
            pq.push(-a * b);
            ans = ((ans % 1000000007) * ((a * b) % 1000000007)) % 1000000007;
        }
        cout << ans % 1000000007 << '\n';
    }
}