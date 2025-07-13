#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a = 0, b;
    for (int i = 0; i < 4; i++) {
        cin >> b;
        a += b;
    }
    cout << (a <= 1500 ? "Yes" : "No");
}