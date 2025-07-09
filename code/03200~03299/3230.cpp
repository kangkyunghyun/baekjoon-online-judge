#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> first(n, 999), second(m, 999);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < n; j++)
            if (first[j] >= x)
                first[j]++;
        first[i] = x;
    }
    vector<int> secMem(m);
    for (int i = 0; i < n; i++)
        if (first[i] <= m)
            secMem[first[i] - 1] = i + 1;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < m; j++)
            if (second[j] >= x)
                second[j]++;
        second[i] = x;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < m; i++)
        ans.push_back({second[i], secMem[m - i - 1]});
    sort(ans.begin(), ans.end());
    for (int i = 0; i < 3; i++)
        cout << ans[i].second << '\n';
}