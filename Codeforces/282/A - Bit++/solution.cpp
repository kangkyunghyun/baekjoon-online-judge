#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x = 0;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s[0] == '+' || s[2] == '+')
            x++;
        else
            x--;
    }
    cout << x;
}