#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    double n;
    cin >> n;
    vector<pair<double, double>> v;
    v.push_back({n, n});
    v.push_back({n, n / sqrt(3)});
    v.push_back({2 / (sqrt(3) + 1) * n, 2 / (sqrt(3) + 1) * n});
    v.push_back({n / sqrt(3), n});
    v.push_back({n, n});
    double a = 0, b = 0;
    for (int i = 1; i <= 4; i++) {
        a += v[i - 1].first * v[i].second;
        b += v[i - 1].second * v[i].first;
    }
    cout.precision(6);
    cout << fixed << (double)abs(a - b) / 2;
}