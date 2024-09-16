#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x;
    string s;
    cin >> x >> s;
    int m=0,f=0,gap=0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'M') {
            int tmpGap = abs(m+1-f);
            if (tmpGap > x) {
                if (i == s.size()-1)
                    break;
                if (s[i+1] == 'M')
                    break;
                gap = abs(f+1-m);
                f++;
                s[i+1] = s[i];
                continue;
            }
            gap = tmpGap;
            m++;
        } else {
            int tmpGap = abs(f+1-m);
            if (tmpGap > x) {
                if (i == s.size()-1)
                    break;
                if (s[i+1] == 'W')
                    break;
                gap = abs(m+1-f);
                m++;
                s[i+1] = s[i];
                continue;
            }
            gap = tmpGap;
            f++;
        }
    }
    cout << m+f;
}