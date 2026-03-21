#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y,a,m=-1;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            cin >> a;
            if (a > m) {
                m = a;
                x=i;
                y=j;
            }
        }
    cout << m << '\n';
    cout << x+1 << ' ' << y+1;
    return 0;
}