#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << "@@@";
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << '@';
        cout << '\n';
    }
    for (int i = 0; i < n * 3; i++) {
        for (int j = 0; j < n; j++)
            cout << '@';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << '@';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << '@';
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << '@';
        for (int j = 0; j < n; j++)
            cout << ' ';
        for (int j = 0; j < n; j++)
            cout << "@@@";
        cout << '\n';
    }
}