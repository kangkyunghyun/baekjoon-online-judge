#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    vector<string> v;
    while (cin >> s)
        v.push_back(s);
    v.pop_back();
    int ans = 0;
    for (string i : v)
        if (s != i && i.find(s) == 0)
            ans++;
    cout << ans;
}