#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int fib[46] = {0, 1};
    for (int i = 2; i <= 45; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans;
        for (int i = 45; i > 0; i--)
            if (n >= fib[i]) {
                n -= fib[i];
                ans.push_back(fib[i]);
                if (n == 0)
                    break;
            }
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}