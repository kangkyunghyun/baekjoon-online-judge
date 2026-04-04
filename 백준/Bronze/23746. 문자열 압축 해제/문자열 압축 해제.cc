#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, e;
    cin >> n;
    map<char, string> m;
    while (n--) {
        string a;
        char b;
        cin >> a >> b;
        m[b] = a;
    }
    string x, ans = "";
    cin >> x >> s >> e;
    for (char c : x) {
        ans += m[c];
    }
    for (int i = s - 1; i < e; i++)
        cout << ans[i];
    
}