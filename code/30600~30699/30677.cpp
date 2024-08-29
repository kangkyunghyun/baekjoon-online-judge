#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, k, c, r;
    cin >> n >> k >> c >> r;
    vector<int> base(k),s(k),p(k), skill(k);
    for(int i = 0; i<k; i++)
        cin >> base[i];
    for(int i = 0; i<k; i++)
        cin >> s[i];
    for(int i = 0; i<k; i++)
        cin >> p[i];
    int P = 0, stardust = 0, combo = 0;
    while(n--) {
        int l;
        cin >> l;
        if (l == 0) {
            P = max(P-r, (int)0);
            combo = 0;
            continue;
        }
        stardust += (int)((double)base[l-1]*(combo*c+100)*(skill[l-1]*s[l-1]+100)/10000);
        skill[l-1]++;
        combo++;
        P+=p[l-1];
        if (P > 100) {
            cout << -1;
            return 0;
        }
    }
    cout << stardust;
}