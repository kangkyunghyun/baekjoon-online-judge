#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> sieve(1299710, 1), prime;
    for (int i = 2; i <= 1299709; i++)
        if (sieve[i]) {
            prime.push_back(i);
            for (int j = i * 2; j <= 1299709; j += i)
                sieve[j] = 0;
        }
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        if (sieve[k]) {
            cout << "0\n";
            continue;
        }
        auto it = lower_bound(prime.begin(), prime.end(), k);
        int a = *it;
        if (*it > k) {
            --it;
            cout << a - *it << '\n';
        } else {
            ++it;
            cout << *it - a << '\n';
        }
    }
}