#include <bits/stdc++.h>
using namespace std;

signed main() {
    int y, c, p;
    cin >> y >> c >> p;
    c /= 2;
    cout << min({y, c, p});
}