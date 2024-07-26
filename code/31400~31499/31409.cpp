#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ans=0;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] != i+1)
			continue;
		if(i == 0)
			v[i] = n;
		else
			v[i] = i;
		ans++;
	}
	cout<<ans<<'\n';
	for(int i:v)
		cout<<i<<' ';
}