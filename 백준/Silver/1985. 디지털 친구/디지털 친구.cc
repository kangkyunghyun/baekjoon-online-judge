#include <bits/stdc++.h>
using namespace std;
#define int long long

bool almost(set<char> a, string b) {
    for (int i = 0; i < b.size() - 1; i++) {
        if (i == 0 && b[i] == '1')
            continue;
        if (b[i] > '0' && b[i + 1] < '9') {
            b[i]--, b[i + 1]++;
            if (a == set<char>(b.begin(), b.end()))
                return true;
            b[i]++, b[i + 1]--;
        }
        if (b[i + 1] > '0' && b[i] < '9') {
            b[i]++, b[i + 1]--;
            if (a == set<char>(b.begin(), b.end()))
                return true;
            b[i]--, b[i + 1]++;
        }
    }
    return false;
}

signed main() {
    string a, b, ans;
    while (cin >> a >> b) {
        set<char> aSet(a.begin(), a.end()), bSet(b.begin(), b.end());
        if (aSet == bSet)
            ans = "friends";
        else if (almost(aSet, b) || almost(bSet, a))
            ans = "almost friends";
        else
            ans = "nothing";
        cout << ans << '\n';
    }
}