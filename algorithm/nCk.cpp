#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1'000'000'007
#define MAX 4'000'001

int factorial[MAX];

pair<int, int> inv(int a, int b) {
    if (a == 0)
        return {0, 1};
    if (b == 0)
        return {1, 0};
    pair<int, int> prev = inv(b, a % b);
    int x = ((prev.second % MOD) + MOD) % MOD;
    int y = prev.first - (a / b) * x;
    return {x, y};
}

int nCk(int n, int k) {
    return ((factorial[n] * inv(factorial[k], MOD).first) % MOD * inv(factorial[n - k], MOD).first) % MOD;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    factorial[0] = 1;
    for (int i = 1; i <= MAX; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
    int m;
    cin >> m;
    while (m--) {
        int n, k;
        cin >> n >> k;
        cout << nCk(n, k) << '\n';
    }
    return 0;
}