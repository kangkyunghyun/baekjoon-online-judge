#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ans=1;
    cin>>n;
    for(int i=1;i<n;i+=2){
        ans*=i;
    }
    cout<<ans;
}