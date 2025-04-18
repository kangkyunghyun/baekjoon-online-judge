#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int time = 900, day = 0;
    vector<int> add = {180, 180, 1080 + k}, ans;
    while (day <= n) {
        for (int i = 0; i < 3 && day <= n; i++) {
            if (day == n)
                ans.push_back(time);
            time += add[i];
            day += time / 1440;
            time %= 1440;
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << (i / 60 < 10 ? "0" : "") << i / 60 << ':' << (i % 60 < 10 ? "0" : "") << i % 60 << '\n';
}