#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    for (int k = 0; k < n; k++) {
        int find = v[k], i = 0, j = n - 1;
        while (i < j)
            if (v[i] + v[j] == find) {
                if (i != k && j != k) {
                    ans++, i++, j--;
                    break;
                } else if (i == k)
                    i++;
                else if (j == k)
                    j--;
            } else if (v[i] + v[j] < find)
                i++;
            else
                j--;
    }
    cout << ans;
}