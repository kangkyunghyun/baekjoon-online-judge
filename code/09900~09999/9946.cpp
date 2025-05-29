#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int cnt = 1;
    while (1) {
        string a, b;
        cin >> a >> b;
        if (a == "END")
            break;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout << "Case " << cnt++ << ": ";
        cout << (a == b ? "same\n" : "different\n");
    }
}