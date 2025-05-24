#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cin >> x;
    int left = 0, right = n - 1;
    while (left < right) {
        if (v[left] + v[right] == x) {
            ans++;
            left++;
            right--;
        } else if (v[left] + v[right] > x)
            right--;
        else
            left++;
    }
    cout << ans;
}