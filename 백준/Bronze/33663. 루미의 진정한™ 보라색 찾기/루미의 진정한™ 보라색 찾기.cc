#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int a[6], r, g, b;
    for (int& i : a)
        cin >> i;
    cin >> r >> g >> b;
    int M = max({r, g, b}), m = min({r, g, b});
    int v = M;
    double s = (double)(v - m) / v * 255;
    double h = (v == r ? (double)(g - b) / (v - m) * 60 : (v == g ? (double)(b - r) / (v - m) * 60 + 120 : (double)(r - g) / (v - m) * 60 + 240));
    h += h < 0 ? 360 : 0;
    cout << (a[0] <= h && h <= a[1] && a[2] <= s && s <= a[3] && a[4] <= v && v <= a[5] ? "Lumi will like it." : "Lumi will not like it.");
}