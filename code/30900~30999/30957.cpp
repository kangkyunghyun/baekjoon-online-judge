#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string str;
    cin >> n >> str;
    int b=0, s=0, a=0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'B')
            b++;
        else if (str[i] == 'S')
            s++;
        else
            a++;
    }
    int m = max(b,max(s,a));
    if (b == s && s == a)
        cout << "SCU";
    else {
        if (m == b)
            cout << "B";
        if (m == s)
            cout << "S";
        if (m == a)
            cout << "A";
    }
}