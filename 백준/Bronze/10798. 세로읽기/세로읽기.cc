#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s[5];
    int size = 0;
    for (string& i : s) {
        cin >> i;
        size = max(size, (int)i.size());
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < 5; j++) {
            if (s[j].size() <= i)
                continue;
            cout << s[j][i];
        }
}