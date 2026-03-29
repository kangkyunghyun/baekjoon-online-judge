#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    while (n--) {
        int m, ans[2], cnt = 0;
        cin >> m;
        for (int i = 0; i < 64; i++)
            if (m & (1LL << i))
                ans[cnt++] = i;
        if (cnt == 1)
            cout << ans[0] - 1 << ' ' << ans[0] - 1 << '\n';
        else
            cout << ans[0] << ' ' << ans[1] << '\n';
    }
}