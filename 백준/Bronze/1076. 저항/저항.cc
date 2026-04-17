#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    map<string, int> m;
    for (int i = 0; i < 10; i++)
        m[s[i]] = i;
    string a, b, c;
    cin >> a >> b >> c;
    cout << (int)((m[a] * 10 + m[b]) * pow(10, m[c]));
}