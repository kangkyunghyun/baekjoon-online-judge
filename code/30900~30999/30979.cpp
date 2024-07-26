#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n,s=0,tmp;
    cin >> t >> n;
    
    for(int i=0; i<n; i++){
        cin >> tmp;
        s+=tmp;
    }
    if (s >= t)
        cout << "Padaeng_i Happy";
    else
        cout << "Padaeng_i Cry";
}