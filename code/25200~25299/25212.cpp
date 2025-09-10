#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, arr[10], ans = 0;
vector<int> visited(10, 0);

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void dfs(int a, int b, int curr) {
    if (100 * a > 101 * b)
        return;
    if ((100 * a >= 99 * b) && (100 * a <= 101 * b)) {
        ans++;
    }
    for (int i = curr + 1; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            int c = arr[i];
            int A = a * c + b, B = b * c;
            int g = gcd(A, B);
            dfs(A / g, B / g, i);
            visited[i] = 0;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dfs(0, 1, -1);
    cout << ans;
}