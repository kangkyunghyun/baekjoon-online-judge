#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    int a[10] = {0};
    for (char c : s)
        a[c - '0']++;
    a[6] = (a[6] + a[9] + 1) / 2;
    a[9] = 0;
    cout << *max_element(a, a + 10);
}