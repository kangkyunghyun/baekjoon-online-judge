#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << pow(n / 2 + 1, 2);
    else
        cout << (n / 2 + 1) * (n / 2 + 2);
}