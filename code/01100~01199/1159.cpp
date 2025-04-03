#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, flag = 0;
    cin >> n;
    int a[26] = {0};
    while (n--) {
        string s;
        cin >> s;
        a[s[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (a[i] >= 5) {
            cout << (char)(i + 'a');
            flag = 1;
        }
    if (!flag)
        cout << "PREDAJA";
}