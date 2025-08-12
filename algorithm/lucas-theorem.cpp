// Lucas-Theorem O(NlogN)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 4'000'001

int fac[MAX], inv[MAX];

int pow(int n, int k, int mod) {
    int ret = 1, base = n % mod;
    while (k) {
        if (k % 2)
            ret = (ret * base) % mod;
        base = (base * base) % mod;
        k /= 2;
    }
    return ret;
}

int nCk(int n, int k, int mod) {
    return (fac[n] * ((inv[k] * inv[n - k]) % mod)) % mod;
}

int lucas(int n, int k, int mod) {
    int ret = 1;
    while (n || k) {
        if (n % mod < k % mod)
            ret = 0;
        ret = ret * nCk(n % mod, k % mod, mod) % mod;
        n /= mod, k /= mod;
    }
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, mod;
    cin >> n >> k >> mod;
    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    for (int i = 0; i < MAX; i++)
        inv[i] = pow(fac[i], mod - 2, mod);
    cout << lucas(n, k, mod);
    return 0;
}