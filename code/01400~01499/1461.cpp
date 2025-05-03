#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> positive, negative;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0)
            positive.push_back(x);
        else
            negative.push_back(-x);
    }
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
    int pSize = positive.size();
    int nSize = negative.size();
    for (int i = pSize - 1; i >= 0; i -= m)
        ans += positive[i] * 2;
    for (int i = nSize - 1; i >= 0; i -= m)
        ans += negative[i] * 2;
    if (pSize > 0 && nSize > 0)
        ans -= max(positive[pSize - 1], negative[nSize - 1]);
    else if (pSize > 0)
        ans -= positive[pSize - 1];
    else
        ans -= negative[nSize - 1];
    cout << ans;
}