#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (char c : s) {
        ans += c - 'A' + 1;
    }
    cout << ans;
}