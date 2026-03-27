#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> a(n), b(n);
    for (auto& s : a)
        cin >> s;
    for (auto& s : b)
        cin >> s;
    for (int i = 0; i < n - 2; i++)
        for (int j = 0; j < m - 2; j++)
            if (a[i][j] != b[i][j]) {
                ans++;
                for (int x = i; x < i + 3; x++)
                    for (int y = j; y < j + 3; y++)
                        a[x][y] = a[x][y] == '0' ? '1' : '0';
            }
    cout << (a == b ? ans : -1);
}