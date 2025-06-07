#include <bits/stdc++.h>
using namespace std;
#define int long long

// int gcd(int a, int b) {
//   if (b==0)
//     return a;
//   return gcd(b, a % b);
// }

// Euclidean
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << ' ' << lcm(n, m);

    return 0;
}