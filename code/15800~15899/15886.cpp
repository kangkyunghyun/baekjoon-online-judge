#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, idx = 0, cnt = 0;
    string s;
    cin >> n >> s;
    while (s.find("EW", idx) != string::npos) {
        idx = s.find("EW", idx) + 1;
        cnt++;
    }
    cout << cnt;
}