#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        bool isPal = true;
        for (int a = 0, b = t.size()-1; a < b; a++, b--)
            if (t[a] != t[b]) {
                isPal = false;
                break;
            }
        if (isPal)
            cnt++;
    }
    cout << cnt * (cnt - 1);
}