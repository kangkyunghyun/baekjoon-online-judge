#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, d, h, k, u;
        cin >> n >> d >> h >> k >> u;
        cout << "YES\n";
        if (k <= n && u <= n) {
            for (int i = 0; i < k; i++)
                cout << 'K';
            for (int i = 0; i < d; i++)
                cout << 'D';
            for (int i = 0; i < h; i++)
                cout << 'H';
            for (int i = 0; i < u; i++)
                cout << 'U';
        } else {
            for (int i = 0; i < d; i++)
                cout << 'D';
            for (int i = 0; i < k; i++)
                cout << 'K';
            for (int i = 0; i < u; i++)
                cout << 'U';
            for (int i = 0; i < h; i++)
                cout << 'H';
        }
        cout << '\n';
    }
}