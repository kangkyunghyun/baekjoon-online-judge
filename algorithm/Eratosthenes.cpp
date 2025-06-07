// Eratosthenes O(nlog(log n))
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> sieve(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
        if (sieve[i])
            for (int j = i * 2; j <= n; j += i)
                sieve[j] = 0;

    for (int i = 2; i <= n; i++)
        if (sieve[i])
            cout << i << ' ';

    return 0;
}