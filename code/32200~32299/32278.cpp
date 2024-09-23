#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    if (n >= -32768 && n <= 32767)
        cout << "short";
    else if (n >= -2147483648 && n <= 2147483647)
        cout << "int";
    else
        cout << "long long";
}