#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;
    int x = min(a+b, 2*n-a-b);
    int ans = 0;
    for (int i = 0, j = pow(2,n-1); i < x; i++, j /= 2) 
        ans += j;
    cout << ans;
}