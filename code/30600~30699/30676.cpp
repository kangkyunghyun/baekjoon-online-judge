#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
	cin >> n;
	if (n >= 620)
		cout << "Red";
	else if (n >= 590)
		cout << "Orange";
	else if (n >= 570)
		cout << "Yellow";
	else if (n >= 495)
		cout << "Green";
	else if (n >= 450)
		cout << "Blue";
	else if (n >= 425)
		cout << "Indigo";
	else
		cout << "Violet";
}