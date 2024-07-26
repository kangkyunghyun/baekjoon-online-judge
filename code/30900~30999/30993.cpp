#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,c,ans=0;
    cin>>n>>a>>b>>c;
    vector<int> v;
    for (int i = 0; i < a; i++)
    v.push_back(0);
    for (int i = 0; i < b; i++)
    v.push_back(1);
    for (int i = 0; i < c; i++)
    v.push_back(2);
    do{
        ans++;
    } while(next_permutation(v.begin(),v.end()));
    cout<<ans;
}