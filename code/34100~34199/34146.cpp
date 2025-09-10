#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int cnt[10001] = {0};
    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (m == 1) {
        cout << "YES";
        return 0;
    }
    int odd = 0;
    for (int i = 0; i <= 10000; i++) {
        if (cnt[i] % 2) {
            odd++;
        }
    }
    if (odd > n) {
        cout << "NO";
        return 0;
    }
    if (n % 2 == 0 && odd % 2) {
        cout << "NO";
        return 0;
    }
    if (m % 2 == 0 && odd > 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}