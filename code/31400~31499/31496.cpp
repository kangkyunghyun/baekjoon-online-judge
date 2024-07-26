#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ans=0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		string name;
		int num;
		cin >> name >> num;
		int idx = 0;
		vector<string> v;
		while(name.find('_',idx) != -1) {
			int x = name.find('_',idx);
			v.push_back(name.substr(idx,x-idx));
			idx = x+1;
		}
		v.push_back(name.substr(idx,name.size()-idx));
		if (find(v.begin(),v.end(),s) != v.end())
			ans+=num;
	}
	cout << ans;
}