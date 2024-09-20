#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int prev[3], curr[3], m[3] = {0}, M[3] = {0};
    for (int i = 0; i < n; i++) {
        cin >> curr[0] >> curr[1] >> curr[2];
        for (int j = 0; j < 3; j++)
            prev[j] = m[j];
        m[0] = min(prev[0], prev[1]) + curr[0];
        m[1] = min(prev[0],min(prev[1], prev[2])) + curr[1];
        m[2] = min(prev[1], prev[2]) + curr[2];
        for (int j = 0; j < 3; j++)
            prev[j] = M[j];
        M[0] = max(prev[0], prev[1]) + curr[0];
        M[1] = max(prev[0],max(prev[1], prev[2])) + curr[1];
        M[2] = max(prev[1], prev[2]) + curr[2];
    }
    cout << max(M[0], max(M[1], M[2])) << ' ' << min(m[0], min(m[1], m[2]));
}