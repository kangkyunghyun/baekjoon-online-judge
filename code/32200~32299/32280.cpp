#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<string, string> a, pair<string, string> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    vector<pair<string, string>> v(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    string t;
    cin >> t;
    bool teacher = false;
    for (int i = 0; i <= n; i++) {
        if (v[i].second == "teacher") {
            teacher = true;
            continue;
        }
        if (teacher && v[i].first >= t)
            ans++;
    }
    cout << ans;
}