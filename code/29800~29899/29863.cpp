#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
	cin >> a >> b;
	if (a > b)
		cout << 24-a+b;
	else
		cout << b-a;
}