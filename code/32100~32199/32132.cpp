#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 2; i < n; i++)
        while (s[i - 2] == 'P' && s[i - 1] == 'S' && (s[i] == '4' || s[i] == '5'))
            s.erase(i, 1);
    cout << s;
}