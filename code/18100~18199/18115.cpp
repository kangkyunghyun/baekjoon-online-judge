#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n;i++)
		cin>>v[i];
	deque<int> dq;
	for(int i = n-1; i >= 0; i--) {
		if (v[i] == 1) {
			dq.push_back(n-i);
		} else if (v[i] == 2) {
			int tmp = dq.back();
			dq.pop_back();
			dq.push_back(n-i);
			dq.push_back(tmp);
		} else {
			dq.push_front(n-i);
		}
	}
	for(int i=n-1;i>=0;i--)
		cout<<dq[i]<<' ';
}