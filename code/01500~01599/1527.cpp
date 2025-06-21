#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b, ans = 0;

void f(int n) {
    if (n > b)
        return;
    if (a <= n && n <= b)
        ans++;
    f(n * 10 + 4);
    f(n * 10 + 7);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    f(4);
    f(7);
    cout << ans;
}