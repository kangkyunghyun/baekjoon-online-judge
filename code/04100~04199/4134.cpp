#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        while (!isPrime(n++))
            ;
        cout << n - 1 << '\n';
    }
}