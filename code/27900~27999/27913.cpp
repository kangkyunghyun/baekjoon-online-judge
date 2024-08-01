#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, q, ans=0;
    cin >> n >> q;
    string s = "SciComLove";
    string str = "";
    for (int i = 0; i < n; i++) {
        int j = i%10;
        str += s[j];
        if (j == 0 || j == 3 || j == 6)
            ans++;
    }

    while(q--) {
        int b;
        cin >> b;
        int a = b-1;
        if (str[a] >= 'a' && str[a] <= 'z') {
            str[a] -= 32;
            ans++;
        } else {
            str[a] += 32;
            ans--;
        }
        cout << ans << '\n';
    }
}