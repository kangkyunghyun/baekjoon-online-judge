#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    vector<int> ans;
    if (a < b)
        swap(a, b);
    while (a > 0) {
        ans.push_back(a % 10 + b % 10);
        a /= 10;
        b /= 10;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
}