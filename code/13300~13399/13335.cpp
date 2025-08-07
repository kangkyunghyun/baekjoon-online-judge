#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, w, L, sum = 0, ans = 0;
    cin >> n >> w >> L;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        while (1) {
            if (q.size() == w) {
                sum -= q.front();
                q.pop();
            }
            if (sum + a[i] <= L)
                break;
            q.push(0);
            ans++;
        }
        q.push(a[i]);
        sum += a[i];
        ans++;
    }
    cout << ans + w;
}