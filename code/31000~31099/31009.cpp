#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,ans=0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        string d;
        int c;
        cin >> d >> c;
        if (d == "jinju") {
            cout << c << '\n';
            m = c;
        }
        v.push_back(c);
    }
    for (int i = 0; i < n; i++) {
		if (v[i] > m)
			ans++;
	}
	cout<<ans;
}