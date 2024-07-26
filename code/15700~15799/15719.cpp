#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, s = 0;
    cin >> n;
    vector<int> v(n,0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    cout << s - (n*(n+1)/2)+n;
}