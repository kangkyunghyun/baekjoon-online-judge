#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    for (int a = 1; a <= n; a++) {     // 택희
        for (int b = 1; b <= n; b++) { // 영훈
            int c = n - a - b;         // 남규
            if (a + b + c != n)
                continue;
            if (c < b + 2)
                continue;
            if (c == 0)
                continue;
            if (a % 2 == 1)
                continue;
            ans++;
        }
    }
    cout << ans;
}