#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int g = gcd(a, b);
        cout << a * b / g << ' ' << g << '\n';
    }
}