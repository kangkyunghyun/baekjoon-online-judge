#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int ans;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'd') {
			if (i == 0) {
				ans = 10;
			} else {
				if (s[i-1] == 'd') {
					ans *= 9;
				} else {
					ans *= 10;
				}
			}
		} else {
			if (i == 0) {
				ans = 26;
			} else {
				if (s[i-1] == 'c') {
					ans *= 25;
				} else {
					ans *= 26;
				}
			}
		}
	}
	cout << ans;
}