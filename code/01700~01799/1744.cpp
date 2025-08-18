#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0, zero = 0;
    cin >> n;
    priority_queue<int> plus, minus;
    while (n--) {
        int x;
        cin >> x;
        if (x == 1)
            ans++;
        else if (x > 0)
            plus.push(x);
        else if (x < 0)
            minus.push(-x);
        else
            zero++;
    }
    while (plus.size() >= 2) {
        int a = plus.top();
        plus.pop();
        int b = plus.top();
        plus.pop();
        ans += a * b;
    }
    if (!plus.empty())
        ans += plus.top();
    while (minus.size() >= 2) {
        int a = minus.top();
        minus.pop();
        int b = minus.top();
        minus.pop();
        ans += a * b;
    }
    if (!minus.empty() && !zero)
        ans -= minus.top();
    cout << ans;
}