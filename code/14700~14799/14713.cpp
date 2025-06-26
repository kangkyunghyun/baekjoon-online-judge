#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    vector<queue<string>> q(n);
    for (int i = 0; i < n; i++) {
        string s, tmp;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> tmp)
            q[i].push((string)tmp);
    }
    string l, tmp;
    getline(cin, l);
    stringstream ss(l);
    while (ss >> tmp) {
        int flag = 0;
        for (int i = 0; i < n && !flag; i++)
            if (!q[i].empty() && q[i].front() == tmp) {
                q[i].pop();
                flag = 1;
            }
        if (!flag) {
            cout << "Impossible";
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        if (!q[i].empty()) {
            cout << "Impossible";
            return 0;
        }
    cout << "Possible";
}