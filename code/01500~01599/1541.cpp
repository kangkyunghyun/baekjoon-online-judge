#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, tmp;
    cin >> s;
    vector<string> v;
    stringstream ss(s);
    vector<int> a;
    while (getline(ss, tmp, '-'))
        v.push_back(tmp);
    for (string i : v) {
        int t = 0;
        stringstream sss(i);
        while (getline(sss, tmp, '+'))
            t += stol(tmp);
        a.push_back(t);
    }
    int ans = a[0];
    for (int i = 1; i < a.size(); i++)
        ans -= a[i];
    cout << ans;
}