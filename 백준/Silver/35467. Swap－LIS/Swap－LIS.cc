#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        if (i > 0 && v[i - 1] > v[i]) {
            cout << "YES\n" << i << ' ' << i + 1;
            return 0;
        }
    cout << "NO";
}