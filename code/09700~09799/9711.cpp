#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int p, q;
        cin >> p >> q;
        vector<int> fibo(p + 1, 0);
        fibo[1] = 1, fibo[2] = 1;
        for (int i = 3; i <= p; i++)
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % q;
        cout << "Case #" << i << ": " << fibo[p] % q << '\n';
    }
}