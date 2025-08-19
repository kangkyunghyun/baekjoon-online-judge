// Euler's Phi O(nlogn)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            ans -= ans / i;
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        ans -= ans / n;
    cout << ans;
}