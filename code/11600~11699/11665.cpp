#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
	cin >> n;
	int a,b,c,x,y,z;
	int min_x=0,min_y=0,min_z=0,max_x=1001,max_y=1001,max_z=1001;
	for(int i=0;i<n;i++) {
		cin >> a>>b>>c>>x>>y>>z;
		min_x=max(min_x,a);
		min_y=max(min_y,b);
		min_z=max(min_z,c);
		max_x=min(max_x,x);
		max_y=min(max_y,y);
		max_z=min(max_z,z);
	}
	if(max_x-min_x<0 || max_y-min_y<0||max_z-min_z<0)
		cout<<0;
	else
	cout<<(max_x-min_x)*(max_y-min_y)*(max_z-min_z);
}