#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int l;
    string s;
    cin >> l >> s;
    vector<int> p,c;
    for (int i = 0; i < l; i++) {
        if (s[i] == 'P')
            p.push_back(i);
        else if (s[i] == 'C')
            c.push_back(i);
    }
    for (int i = 0; i < min(p.size(),c.size()); i++) {
        int a = p[i], b = c[i];
        s[a] = 'C';
        s[b] = 'P';
    }
    cout << s;
}