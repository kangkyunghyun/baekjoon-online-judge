#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
 
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), s(n);
        for (int &i : p)
            cin >> i;
        for (int &i : s)
            cin >> i;
        vector<int> a(p);
        for (int i = 0; i < n; i++) {
            if (a[i] % s[i] == 0)
                continue;
            a[i] = lcm(a[i], s[i]);
        }
        vector<int> newP(n, a[0]), newS(n, a[n - 1]);
        for (int i = 1; i < n; i++) {
            newP[i] = gcd(newP[i - 1], a[i]);
            newS[i] = gcd(newS[i - 1], a[n - i - 1]);
        }
        reverse(newS.begin(), newS.end());
        cout << (p == newP && s == newS ? "YES
" : "NO
");
    }
}