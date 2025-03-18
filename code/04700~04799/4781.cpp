#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    while (1) {
        int n;
        double m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        int knapsack[10001] = {0};
        int M = (int)(m * 100 + 0.5);
        while (n--) {
            int c;
            double p;
            cin >> c >> p;
            int tmp = (int)(p * 100 + 0.5);
            for (int i = tmp; i <= M; i++)
                knapsack[i] = max(knapsack[i], knapsack[i - tmp] + c);
        }
        cout << knapsack[M] << '\n';
    }
}