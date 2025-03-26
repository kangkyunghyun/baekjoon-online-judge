#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> knapsack(n + 1, 0);
    while (k--) {
        int v, w;
        cin >> v >> w;
        for (int i = n; i >= w; i--)
            knapsack[i] = max(knapsack[i], knapsack[i - w] + v);
    }
    cout << knapsack[n];
}