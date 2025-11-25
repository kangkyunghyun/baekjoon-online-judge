#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, ans = 2;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0, h, m; i < n; v[i++] = h * 60 + m)
        scanf("%d:%d", &h, &m);
    for (int i = 0; i < n; i++) {
        if (i < n - 2 && v[i + 2] - v[i] <= 10)
            ans = 0;
        else if (i < n - 1 && v[i + 1] - v[i] <= 10)
            ans = min(ans, 1);
        else
            ans = min(ans, 2);
    }
    printf("%d", ans);
}