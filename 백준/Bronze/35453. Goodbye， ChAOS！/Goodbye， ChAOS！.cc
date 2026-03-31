#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    map<int, int> m;
    m[232] = 2017;
    m[88] = 2018;
    m[754] = 2019;
    m[29] = 2020;
    m[28] = 2021;
    m[1015] = 2022;
    m[1295] = 2023;
    m[1073] = 2024;
    m[348] = 2025;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            string s;
            cin >> s;
            if (m.find(s.size()) == m.end())
                cout << "Goodbye, ChAOS!";
            else
                cout << m[s.size()];
        } else {
            string s1, s2;
            cin >> s1 >> s2;
            if (m.find(s1.size() * s2.size()) == m.end())
                cout << "Goodbye, ChAOS!";
            else
                cout << m[s1.size() * s2.size()];
        }
        cout << '\n';
    }
}