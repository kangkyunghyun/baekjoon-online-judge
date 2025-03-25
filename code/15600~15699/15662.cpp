#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, k, ans = 0;
string gear[1001];
vector<pair<int, int>> v;
vector<int> visited(1001, 0);

void solve(int n, int d) {
    visited[n] = 1;
    char right = gear[n][2];
    char left = gear[n][6];
    if (n != t) {
        char nextLeft = gear[n + 1][6];
        if (right != nextLeft && !visited[n + 1])
            solve(n + 1, -d);
    }
    if (n != 1) {
        char prevRight = gear[n - 1][2];
        if (left != prevRight && !visited[n - 1])
            solve(n - 1, -d);
    }
    v.push_back({n, d});
}

void rotate(int n, int d) {
    if (d == 1) {
        char tmp = gear[n][7];
        for (int i = 7; i >= 1; i--)
            gear[n][i] = gear[n][i - 1];
        gear[n][0] = tmp;
    } else {
        char tmp = gear[n][0];
        for (int i = 0; i < 7; i++)
            gear[n][i] = gear[n][i + 1];
        gear[n][7] = tmp;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    for (int i = 1; i <= t; i++)
        cin >> gear[i];
    cin >> k;
    while (k--) {
        int n, d;
        cin >> n >> d;
        solve(n, d);
        for (auto [i, j] : v)
            rotate(i, j);
        v.clear();
        fill(visited.begin(), visited.end(), 0);
    }
    for (int i = 1; i <= t; i++)
        if (gear[i][0] == '1')
            ans++;
    cout << ans;
}