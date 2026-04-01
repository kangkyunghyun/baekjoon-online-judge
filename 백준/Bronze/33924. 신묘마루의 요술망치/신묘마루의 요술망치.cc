#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    for (char c : s) {
        if (c == 'A') {
            n += n <= 2 ? 2 : -2;
        } else if (c == 'B') {
            n += n & 1 ? 1 : -1;
            m += m & 1 ? 1 : -1;
        } else if (c == 'C') {
            n = 5 - n;
            m += m & 1 ? 1 : -1;
        } else {
            if (n == 1 && m == 1)
                m++;
            else if (n == 4 && m == 2)
                m--;
            else if (m == 1)
                n--;
            else
                n++;
        }
    }
    cout << n << ' ' << m;
}