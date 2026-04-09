#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n && n != -1) {
        vector<int> cd{1};
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cd.push_back(i);
                cd.push_back(n / i);
            }
        }
        cd.erase(unique(cd.begin(), cd.end()), cd.end());
        sort(cd.begin(), cd.end());
        if (n == accumulate(cd.begin(), cd.end(), 0)) {
            cout << n << " = ";
            for (int i = 0; i < cd.size() - 1; i++)
                cout << cd[i] << " + ";
            cout << cd.back() << '\n';
        } else {
            cout << n << " is NOT perfect.\n";
        }
    }
}