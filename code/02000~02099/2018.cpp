#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, l = 1, r = 1, sum = 1, ans = 0;
    cin >> n;
    while (l <= r)
        if (sum < n)
            sum += ++r;
        else if (sum > n)
            sum -= l++;
        else
            ans++, sum += ++r;
    cout << ans;
}