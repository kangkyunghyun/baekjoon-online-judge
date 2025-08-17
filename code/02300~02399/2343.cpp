#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, left = 0, right = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
        left = max(left, i);
        right += i;
    }
    while (left <= right) {
        int mid = (left + right) / 2;
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (sum + v[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += v[i];
        }
        if (sum)
            cnt++;
        if (cnt > m)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << left;
}