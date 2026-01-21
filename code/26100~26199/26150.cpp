#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, char>> v;
    while (n--) {
        string s;
        int i, d;
        cin >> s >> i >> d;
        v.push_back({i, toupper(s[d - 1])});
    }
    sort(v.begin(), v.end());
    for (auto [_, c] : v)
        cout << c;
}