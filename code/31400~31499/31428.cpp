#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[26]={0};
    char x;
    for (int i = 0; i<n;i++){
        cin>>x;
        a[x-'A']++;
    }
    cin>>x;
    cout<<a[x-'A'];
}