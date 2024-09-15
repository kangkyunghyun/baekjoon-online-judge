#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        s = s.substr(2);
        int size = s.size();
        int a, b, g;
        if (s.find('(') == string::npos) {
            a = stoi(s);
            b = pow(10, size);
        } else {
            size -= 2;
            int start = s.find('(');
            string noInf = "0";
            if (start != 0)
                noInf = s.substr(0, start);
            string inf = s.substr(start + 1, size - start);
            a = stoll(noInf + inf) - stoll(noInf);
            string tmp = "";
            for (int i = 0; i < size - start; i++)
                tmp += '9';
            for (int i = 0; i < start; i++)
                tmp += '0';
            b = stoll(tmp);
        }
        g = gcd(a, b);
        cout << a / g << '/' << b / g << '\n';
    }
}