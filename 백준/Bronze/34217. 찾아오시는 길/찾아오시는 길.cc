#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + c < b + d)
        cout << "Hanyang Univ.";
    else if (a + c > b + d)
        cout << "Yongdap";
    else
        cout << "Either";
}