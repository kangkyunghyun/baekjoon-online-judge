#include <bits/stdc++.h>
using namespace std;
#define int long long

string ans = "";
int n, l, flag = 0;
vector<vector<int>> a(20, vector<int>(26, 0));
vector<string> s(20);
vector<vector<char>> t(20);

void dfs(int depth) {
    if (flag)
        return;
    if (depth == l) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < l; j++)
                if (ans[j] != s[i][j])
                    cnt++;
            if (cnt < 2)
                count++;
        }
        if (count == n) {
            cout << ans;
            flag = 1;
        }
        return;
    }
    for (char j : t[depth]) {
        ans += j;
        dfs(depth + 1);
        ans.pop_back();
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < l; j++)
            a[j][s[i][j] - 'A']++;
    }
    for (int i = 0; i < l; i++) {
        int tmp = 0;
        for (int j = 0; j < 26; j++) {
            if (a[i][j] > tmp) {
                tmp = a[i][j];
                t[i].clear();
                t[i].push_back((char)(j + 'A'));
            } else if (a[i][j] == tmp)
                t[i].push_back((char)(j + 'A'));
        }
    }
    dfs(0);
    if (!flag)
        cout << "CALL FRIEND";
}