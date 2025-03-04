#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x;
    cin >> x;
    for (int i = x + 1; i <= 9999; i++) {
        if (((i / 100) + (i % 100)) * ((i / 100) + (i % 100)) == i) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}