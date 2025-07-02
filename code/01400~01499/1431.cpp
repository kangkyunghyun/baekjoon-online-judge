#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        int x = 0, y = 0, size = a.size();
        for (int i = 0; i < size; i++) {
            if (a[i] >= '0' && a[i] <= '9')
                x += a[i] - '0';
            if (b[i] >= '0' && b[i] <= '9')
                y += b[i] - '0';
        }
        if (x == y)
            return a < b;
        return x < y;
    }
    return a.size() < b.size();
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    for (auto i : v)
        cout << i << '\n';
}
