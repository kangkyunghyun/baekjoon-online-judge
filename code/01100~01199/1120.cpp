#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int ans = 50;
    for (int i = 0; i < b.size() - a.size() + 1; i++) {
        int diff = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] != b[i+j])
                diff++;
        }
        ans = min(ans, diff);
    }
    cout << ans;
}