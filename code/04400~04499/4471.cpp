#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin.ignore();
        getline(cin, s1);
        double x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1;
        cin.ignore();
        getline(cin, s2);
        cin >> x2 >> y2 >> z2;
        cout.precision(2);
        cout << fixed << s1 << " to " << s2 << ": " << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2)) << '\n';
    }
}