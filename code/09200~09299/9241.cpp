#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    int minSize = min(a.size(), b.size()), x = minSize, y = minSize;
    for (int i = 0; i < minSize; i++)
        if (a[i] != b[i]) {
            x = i;
            break;
        }
    for (int i = 0; a.size() - i - 1 >= x && b.size() - i - 1 >= x; i++)
        if (a[a.size() - i - 1] != b[b.size() - i - 1]) {
            y = i;
            break;
        }
    int ans = 0;
    if (x + y >= minSize) {
        if (a.size() <= b.size())
            ans = b.size() - a.size();
    } else
        ans = b.size() - x - y;
    cout << ans;
}