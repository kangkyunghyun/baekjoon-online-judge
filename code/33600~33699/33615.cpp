#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        if (n[n.size() - 1] == '5') {
            cout << "0 5\n";
            continue;
        }
        if (n[n.size() - 2] == '5') {
            cout << n.size() << " 5\n";
            continue;
        }
        int sum = 0;
        for (char c : n)
            sum += c - '0';
        if (sum % 3 == 0) {
            cout << "0 3\n";
        } else if (sum % 3 == 1) {
            cout << n.size() << " 3\n";
        } else {
            if (n.find('5') != string::npos) {
                cout << n.find('5') + 1 << " 3\n";
            } else {
                if (n.size() % 2 == 0) {
                    cout << "0 11\n";
                } else {
                    cout << "1 11\n";
                }
            }
        }
    }
}