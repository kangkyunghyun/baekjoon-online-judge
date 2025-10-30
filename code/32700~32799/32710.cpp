#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int a[101] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 2; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            a[i * j] = 1;
    cout << a[n];
}