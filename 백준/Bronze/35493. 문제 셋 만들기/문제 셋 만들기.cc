#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x % 2)
            cnt++;
    }
    cout << (cnt % 2 && n == 1 ? "NO" : "YES");
}