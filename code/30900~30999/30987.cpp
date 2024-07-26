#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1,x2,a,b,c,d,e;
    cin >> x1>>x2>>a>>b>>c>>d>>e;
    int ans = (a/3*x2*x2*x2+(b-d)/2*x2*x2+(c-e)*x2)-(a/3*x1*x1*x1+(b-d)/2*x1*x1+(c-e)*x1);
    cout<<ans;
}