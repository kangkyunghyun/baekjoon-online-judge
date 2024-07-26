#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	vector<string> v(3);
	for(int i = 0; i < 3; i++)
		cin >> v[i];
	sort(v.begin(),v.end());
	cout << (v[0][0] == 'k' && v[1][0] == 'l' && v[2][0] == 'p' ? "GLOBAL" : "PONIX");
}