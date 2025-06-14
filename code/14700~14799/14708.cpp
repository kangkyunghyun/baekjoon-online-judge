#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int k;
    cin >> k;
    int x = cbrt(k), surface = 6e12;
    vector<vector<int>> ans;
    for (int a = max((int)1, x - 5000); a <= x + 1; a++) {
        for (int b = a; b <= sqrt(k / a) + 1; b++) {
            int c = ceil((double)k / (a * b));
            int tmp = 2 * (a * b + a * c + b * c);
            if (a * b * c >= k)
                if (surface > tmp) {
                    vector<int> t{a, b, c};
                    sort(t.begin(), t.end());
                    surface = tmp;
                    ans.clear();
                    ans.push_back(t);
                } else if (surface == tmp) {
                    vector<int> t{a, b, c};
                    sort(t.begin(), t.end());
                    ans.push_back(t);
                }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i : ans[0])
        cout << i << ' ';
}