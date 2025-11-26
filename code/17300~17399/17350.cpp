#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, flag = 0;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "anj")
            flag = 1;
    }
    cout << (flag ? "뭐야;" : "뭐야?");
}