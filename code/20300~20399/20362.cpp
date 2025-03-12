#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, idx, ans = 0;
    string s, answer;
    cin >> n >> s;
    vector<pair<string, string>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        if (v[i].first == s) {
            answer = v[i].second;
            idx = i;
            break;
        }
    }
    for (int i = idx - 1; i >= 0; i--) {
        if (v[i].second == answer)
            ans++;
    }
    cout << ans;
}