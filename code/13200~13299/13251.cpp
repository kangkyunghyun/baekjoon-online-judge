#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int m, k, sum = 0;
    cin >> m;
    vector<int> v(m);
    for(int i = 0; i < m; i++) {
        cin>> v[i];
        sum += v[i];
    }
    cin >> k;
    double ans = 0;
    for (int i = 0; i < m; i++) {
        if (v[i] < k) continue;
        double tmp = 1.0;
        for (int j = 0; j < k; j++)
            tmp *= (double)(v[i]-j)/(sum-j);
        ans += tmp;
    }
    cout.precision(9);
    cout << fixed << ans;
}