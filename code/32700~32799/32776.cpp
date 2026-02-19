#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int s, ma, f, mb;
    cin >> s >> ma >> f >> mb;
    cout << (s <= ma + f + mb || s <= 240 ? "high speed rail" : "flight");
}