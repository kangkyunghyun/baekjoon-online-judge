#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string s;
    cin >> s;
    int a = 0, b = 0, aN = 0, bN = 0, flag = 0, tmp, ans = 0;
    char op;
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            if (!flag) {
                a *= 8;
                a = aN ? a - (s[i] - '0') : a + (s[i] - '0');
            } else {
                b *= 8;
                b = bN ? b - (s[i] - '0') : b + (s[i] - '0');
            }
        } else {
            if (i == 0) {
                aN = 1;
            } else if (!flag) {
                flag = 1;
                op = s[i];
            } else {
                bN = 1;
            }
        }
    }
    if (op == '+')
        tmp = a + b;
    else if (op == '-')
        tmp = a - b;
    else if (op == '*')
        tmp = a * b;
    else if (op == '/') {
        if (b == 0) {
            cout << "invalid";
            return 0;
        }
        tmp = floor((double)a / b);
    }
    int i = 1;
    while (tmp) {
        ans += i * (tmp % 8);
        i *= 10;
        tmp /= 8;
    }
    cout << ans;
}