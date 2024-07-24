#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> h;

int solve(int left, int right) {
	if (left == right) return h[left];
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid+1, right));
	int lo = mid, hi = mid+1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, 2*height);
	while(left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo-1] < h[hi+1])) {
			hi++;
			height = min(height, h[hi]);
		} else {
			lo--;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi-lo+1));
	}
	return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	while(1) {
		cin >> n;
		if(!n) break;
		h.resize(n);
		for(int i=0;i<n;i++) {
			cin >> h[i];
		}
		cout << solve(0, n-1) << '\n';
	}
}