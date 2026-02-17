#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[20], b[2000001];

void dfs(int depth, int sum) {
    b[sum] = 1;
    if (depth == n)
        return;
    dfs(depth + 1, sum);
    dfs(depth + 1, sum + a[depth]);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0, 0);
    for (int i = 1;; i++)
        if (!b[i]) {
            cout << i;
            break;
        }
}