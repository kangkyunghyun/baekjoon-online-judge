#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    for (int i; m > 0; m--) {
        cin >> i;
        if (i > 0 && i >= k)
            k = 1 + i - k;
        else if (i < 0 && n + i < k)
            k = 2 * n + i + 1 - k;
    }
    cout << k;
}