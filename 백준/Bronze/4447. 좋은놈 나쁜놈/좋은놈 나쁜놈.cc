#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        int g = 0, b = 0;
        for (char c : s) {
            if (c == 'G' || c == 'g') g++;
            if (c == 'B' || c == 'b') b++;
        }
        cout << s << " is " << (g > b ? "GOOD" : (g < b ? "A BADDY" : "NEUTRAL")) << '\n';
    }
}