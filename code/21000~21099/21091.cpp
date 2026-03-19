#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;
    vector<pair<pair<int, int>, char>> ans;
    sort(a.begin(), a.end());
    ans.push_back({{1, n}, 'I'});
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
            continue;
        int m = a[i], M = a[i], j = i;
        for (; j < n; j++) {
            m = min(m, a[j]), M = max(M, a[j]);
            if (a[j] == b[i])
                break;
        }
        if (a[j] == m) {
            sort(a.begin() + i, a.begin() + j + 1);
            ans.push_back({{i + 1, j + 1}, 'I'});
        } else {
            sort(a.begin() + i, a.begin() + j + 1, greater<>());
            ans.push_back({{i + 1, j + 1}, 'D'});
        }
    }
    cout << ans.size() << '\n';
    for (auto [i, c] : ans)
        cout << i.first << ' ' << i.second << ' ' << c << '\n';
}