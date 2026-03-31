#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans += n / i * i;
    cout << ans;
}