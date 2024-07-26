#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
	cin >> n >> k;
	int cnt = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			cnt++;
		else
			v.push_back(b-a);
	}
	if (cnt >= k) {
		cout << 0;
	} else {
		sort(v.begin(), v.end());
		cout << v[k-cnt-1];
	}
}