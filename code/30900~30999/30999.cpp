#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int cnt = 0;
		for (char c : s) {
			if (c == 'O')
				cnt++;
		}
		if (cnt >= (m+1)/2)
			ans++;
	}
	cout << ans;
}