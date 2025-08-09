#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int k;
    cin >> k;
    vector<pair<int, int>> v;
    int x = 0, y = 0;
    for (int i = 0; i < 6; i++) {
        int direction, distance;
        cin >> direction >> distance;
        switch (direction) {
        case 1:
            y += distance;
            break;
        case 2:
            y -= distance;
            break;
        case 3:
            x -= distance;
            break;
        case 4:
            x += distance;
            break;
        default:
            break;
        }
        v.push_back({x, y});
    }
    v.push_back(v[0]);
    int a = 0, b = 0;
    for (int i = 1; i <= 7; i++) {
        a += v[i - 1].first * v[i].second;
        b += v[i - 1].second * v[i].first;
    }
    cout << abs(a - b) / 2 * k;
}