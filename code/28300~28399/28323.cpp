#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int flag = 0, odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && flag) {
            flag = !flag;
            odd++;
        } else if (a[i] % 2 == 1 && !flag) {
            flag = !flag;
            odd++;
        }
    }
    flag = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1 && !flag) {
            flag = !flag;
            even++;
        } else if (a[i] % 2 == 0 && flag) {
            flag = !flag;
            even++;
        }
    }
    cout << max(odd, even);
}