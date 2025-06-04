#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1\n1 2";
        return 0;
    }
    if ((n / 2) % 2 == 0)
        cout << n << '\n';
    else
        cout << n - 1 << '\n';
    for (int i = n - 1; i > 1; i -= 2)
        cout << i << ' ' << i - 1 << '\n';
    for (int i = 0; i < n / 4; i++)
        cout << "1 1\n";
    int cnt = n / 4;
    while (cnt > 1) {
        cout << "0 0\n";
        cnt--;
    }
    if ((n / 2) % 2 && n != 3)
        cout << "0 1\n";
    if ((n / 2) % 2 == 0)
        cout << "0 " << n;
    else
        cout << "1 " << n;
}