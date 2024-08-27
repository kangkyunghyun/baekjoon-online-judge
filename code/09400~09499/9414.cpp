#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int t;
    cin >> t;
    while(t--) {
        int l;
        vector<int> v;
        while(cin>>l){
            if(l==0)
                break;
            v.push_back(l);
        }
        sort(v.begin(),v.end(), greater<>());
        int ans = 0;
        for(int i = 0; i < v.size(); i++)
            ans += 2*pow(v[i],i+1);
        if (ans > 5e6)
            cout << "Too expensive";
        else
            cout << ans;
        cout << '\n';
    }
}