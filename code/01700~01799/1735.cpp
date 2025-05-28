#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = a * d + b * c, f = b * d;
    int g = gcd(e, f);
    cout << e / g << ' ' << f / g;
}