#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int m = v[0];
    vector<int> idx;
    idx.push_back(0);
    for (int i = 1; i < n; i++) {
        if (v[i] == m) {
            idx.push_back(i);
        } else if (v[i] > m) {
            m = v[i];
            idx.clear();
            idx.push_back(i);
        }
    }
    int blue = idx[0];
    int red = n - 1 - idx.back();
    if (red < blue)
        cout << 'B';
    else if (red > blue)
        cout << 'R';
    else
        cout << 'X';
}