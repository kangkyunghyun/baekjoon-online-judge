#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int cnt = n;
    while (n > 1) {
        cnt += n / m;
        n /= m;
    }
    cout << cnt;
}