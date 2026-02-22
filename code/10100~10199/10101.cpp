#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c && c == 60)
        cout << "Equilateral";
    else if (a + b + c == 180 && (a == b || b == c || c == a))
        cout << "Isosceles";
    else if (a + b + c == 180 && a != b && b != c && c != a)
        cout << "Scalene";
    else
        cout << "Error";
}