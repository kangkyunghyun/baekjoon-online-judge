#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 0) {
        cout << "NO";
        return 0;
    }
    while (n > 0) {
        if (n % 3 == 2) {
            cout << "NO";
            return 0;
        }
        n /= 3;
    }
    cout << "YES";
}