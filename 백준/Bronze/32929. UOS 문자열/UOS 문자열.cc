#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x;
    cin >> x;
    string s = "UOS";
    cout << s[(x - 1) % 3];
}