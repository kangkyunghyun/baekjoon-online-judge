#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
int a[10], ans;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for (char c : s)
        a[c - '0']++;
    if (a[3] + a[4] + a[5] + a[6] + a[7] + a[9] != 0)
        ans = 0;
    else if (!a[0] || !a[1] || !a[2] || !a[8])
        ans = 1;
    else if (a[0] != a[1] || a[1] != a[2] || a[2] != a[8])
        ans = 2;
    else
        ans = 8;
    cout << ans;
}