#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        while(n >= 5) {
            for (int i = 0; i<4; i++){
                cout<<'+';
            }
            n -= 5;
            if (n > 0)
            cout<<' ';
        }
        while(n--)
            cout<<'|';
        cout<<'\n';
    }
}