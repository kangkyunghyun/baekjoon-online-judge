#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n;
    vector<int> a(n);
    deque<int> b;
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (a[i] == 0)
            b.push_back(x);
    }
    cin >> m;
    while (m--) {
        int c;
        cin >> c;
        b.push_front(c);
        cout << b.back() << ' ';
        b.pop_back();
    }
}