#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    int cost = 0, gain = 0;
    for (int i = 0; i < m; i++) {
        int tmp;
        if (n < m) {
            tmp = v[i]*n;
            if (i > m-n)
                tmp = v[i]*(m-i);
        } else {
            tmp = v[i]*(m-i); 
        }
        if (gain < tmp) {
            gain = tmp;
            cost = v[i];
        }
    }
    cout << cost << ' ' << gain;
}