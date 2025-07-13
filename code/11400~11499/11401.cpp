#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1'000'000'007
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

int nCk(int n, int k) {
    return (fac[n] * ((inv[k] * inv[n - k]) % MOD)) % MOD;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    for (int i = 0; i <= MAX; i++)
        inv[i] = pow(fac[i], MOD - 2, MOD);
    int n, k;
    cin >> n >> k;
    cout << nCk(n, k);
    return 0;
}