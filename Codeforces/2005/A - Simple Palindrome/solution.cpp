#include <bits/stdc++.h>
using namespace std;
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    string a = "aeiou";
    while (t--) {
        int n;
        cin >> n;
        int x = n % 5;
        for (int i = 0; i < min(n, 5); i++) {
            for (int j = 0; j < n / 5; j++)
                cout << a[i];
            if (x) {
                cout << a[i];
                x--;
            }
        }
        cout << '
';
    }
}