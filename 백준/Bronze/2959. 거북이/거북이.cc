#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a[4];
    for (int& i : a)
        cin >> i;
    sort(a, a + 4);
    cout << a[0] * a[2];
}