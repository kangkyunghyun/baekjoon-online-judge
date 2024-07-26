#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int i, n;
		if (s.find('0') != -1) {
			i = s.find('0');
			n=0;
		} else {
			i = s.find('1');
			n=1;
		}
		if(s.find('!',i)!=-1)
			n=1;
		if(i%2)
			n=!n;
		cout<<n<<'\n';
	}
}