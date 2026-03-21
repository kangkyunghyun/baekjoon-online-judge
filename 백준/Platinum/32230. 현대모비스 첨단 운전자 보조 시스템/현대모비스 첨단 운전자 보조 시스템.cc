#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> matrix(n);
    for (int i = 0; i < n; i++)
        cin >> matrix[i].first >> matrix[i].second;
    if (n <= 2)
        cout << 0;
}