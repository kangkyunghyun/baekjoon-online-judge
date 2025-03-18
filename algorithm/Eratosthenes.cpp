#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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

// O(nlog(log n))