#include <bits/stdc++.h>
using namespace std;
#define int long long

int eulerPhi(int num) {
    int ret = num;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) {
            ret -= ret / i;
            while (num % i == 0)
                num /= i;
        }
    if (num > 1)
        ret -= ret / num;
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 2; i <= n; i++)
        ans += eulerPhi(i);
    cout << ans;
}