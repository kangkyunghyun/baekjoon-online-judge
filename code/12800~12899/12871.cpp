#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    string sa = s, ta = t;
    int ss = s.size(), ts = t.size();
    int l = lcm(ss, ts);
    ss = l / ss, ts = l / ts;
    for (int i = 1; i < ss; i++)
        s += sa;
    for (int i = 1; i < ts; i++)
        t += ta;
    cout << (s == t);
}