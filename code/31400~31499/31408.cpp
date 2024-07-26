#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[100001] = {0};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	if (*max_element(a, a+100001) <= (n+1)/2)
		cout<<"YES";
	else
		cout<<"NO";
}