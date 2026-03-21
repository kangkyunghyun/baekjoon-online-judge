#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n>>a;
    while(--n){
        cin>>b;
        a+=b;
    }
    cout<<a;
    return 0;
}