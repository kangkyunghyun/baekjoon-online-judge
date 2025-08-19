#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    while (1) {
        int n;
        cin >> n;
        if (!n)
            break;
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        int ans = n;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                ans -= ans / i;
                while (n % i == 0)
                    n /= i;
            }
        if (n > 1)
            ans -= ans / n;
        cout << ans << '\n';
    }
}