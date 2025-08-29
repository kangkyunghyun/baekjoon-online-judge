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
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2;
        return 0;
    } else if (isPrime(n)) {
        cout << 1;
        return 0;
    }
    int prime = 0;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i)) {
            prime = i;
            break;
        }
    if (prime)
        cout << (n - prime) / 2 + 1;
    else
        cout << n / 2;
}