#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x, fac[21] = {1, 1}, k = 1;
    cin >> n >> x;
    for (int i = 2; i <= 20; i++)
        fac[i] = fac[i - 1] * i;
    if (x == 1) {
        cin >> k;
        vector<int> visited(n + 1, 0), v(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1, cnt = 1; j <= n; j++) {
                if (visited[j])
                    continue;
                if (cnt * fac[n - i] >= k) {
                    k -= (cnt - 1) * fac[n - i];
                    v[i - 1] = j;
                    visited[j] = 1;
                    break;
                }
                cnt++;
            }
        }
        for (int i : v)
            cout << i << ' ';
    } else {
        vector<int> visited(n + 1, 1);
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            k += (accumulate(visited.begin(), visited.begin() + x, 0) - 1) * fac[n - i];
            visited[x] = 0;
        }
        cout << k;
    }
}