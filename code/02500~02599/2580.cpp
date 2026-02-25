#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[9][9], flag = 0;
vector<pair<int, int>> v;

bool check(int x, int y, int value) {
    for (int i = 0; i < 9; i++)
        if (a[x][i] == value || a[i][y] == value)
            return false;
    x = x / 3 * 3, y = y / 3 * 3;
    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++)
            if (a[i][j] == value)
                return false;
    return true;
}

void dfs(int idx) {
    if (flag)
        return;
    if (idx == v.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << a[i][j] << ' ';
            cout << '\n';
        }
        flag = 1;
    }
    for (int i = 1; i <= 9; i++) {
        int x = v[idx].first, y = v[idx].second;
        if (check(x, y, i)) {
            a[x][y] = i;
            dfs(idx + 1);
            a[x][y] = 0;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
            if (!a[i][j])
                v.push_back({i, j});
        }
    dfs(0);
}