#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int n;
    cin >> n;
	string s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(),s.end());
		int tmp = stoll(s);
		v[i]=tmp;
	}
	sort(v.begin(),v.end());
	for (int i : v)
		cout << i << '\n';
}