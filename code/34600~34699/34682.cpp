#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string n, ans = "";
    cin >> n;
    if (n.size() % 2) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n.size(); i += 2) {
        char a = n[i], b = n[i + 1];
        if (a == '0' || (ans.size() && b == ans.back())) {
            cout << -1;
            return 0;
        }
        for (int j = 0; j < a - '0'; j++)
            ans += b;
    }
    cout << (ans.empty() || ans.front() == '0' ? "-1" : ans);
}