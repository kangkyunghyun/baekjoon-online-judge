#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, k;
    cin >> n >> k;
	vector<int> x(n);
	for(int i=0; i<n; i++) {
		cin >> x[i];
	}
	sort(x.begin(),x.end());
	int ans = 0;
	int lo = x[0], hi = x[0]+k;
	while(lo <= hi) {
		int mid = (lo + hi)/2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (x[i] < mid) {
				cnt += mid-x[i];
			} else {
				break;
			}
		}
		if (cnt > k) {
			hi = mid-1;
		} else {
			ans = mid;
			lo = mid+1;
		}
	}
	cout << ans;
}