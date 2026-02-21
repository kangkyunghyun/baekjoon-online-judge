#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, aSum = 0, bSum = 0, flag = 0;
        cin >> n;
        vector<pair<double, double>> v(n);
        for (auto &[a, b] : v) {
            cin >> a >> b;
            aSum += a;
            bSum += b;
        }
        pair<double, double> mid{aSum / n, bSum / n};
        sort(v.begin(), v.end());
        flag = n % 2 && mid != v[n / 2];
        for (int i = 0; i < n / 2; i++) {
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[n - i - 1];
            if (dist(mid.first, mid.second, x1, y1) != dist(mid.first, mid.second, x2, y2)) {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "no\n" : "yes\n");
    }
}