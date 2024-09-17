#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, g;
    cin >> r >> g;
    int G = gcd(r, g);
    vector<int> v;
    for (int i = 1; i <= sqrt(G); i++)
        if (G % i == 0) {
            v.push_back(i);
            if (G / i != i)
                v.push_back(G / i);
        }
    for (int i : v)
        cout << i << ' ' << r / i << ' ' << g / i << '\n';
}