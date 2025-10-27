#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(26, 0);
    for (char c : s)
        if (c == 'u' || c == 'o' || c == 's' || c == 'p' || c == 'c')
            cnt[c - 'a']++;
    cout << min({cnt['u' - 'a'], cnt['o' - 'a'], cnt['s' - 'a'], cnt['p' - 'a'], cnt['c' - 'a']});
}