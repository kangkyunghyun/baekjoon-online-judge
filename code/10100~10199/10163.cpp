#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[1001][1001];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt = 0;
    cin >> n;
    while (n--) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        cnt++;
        for (int i = x; i < x + w; i++)
            for (int j = y; j < y + h; j++)
                arr[i][j] = cnt;
    }
    vector<int> ans(cnt + 1, 0);
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            ans[arr[i][j]]++;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << "\n";
    }
}