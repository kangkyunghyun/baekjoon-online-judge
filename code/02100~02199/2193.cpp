#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n,1);
    for (int i = 2; i < n; i++)
        v[i] = v[i-1] + v[i-2];
    cout << v[n-1];
}