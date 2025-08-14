#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, dist[201][201], longest[201][201] = {0};
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = i == j ? 0 : INF;
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
        longest[a][b] = max(longest[a][b], c);
        longest[b][a] = max(longest[b][a], c);
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    double ans = INF;
    for (int i = 1; i <= N; i++) {
        double tmp = 0;
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (longest[j][k] != 0) {
                    double left = longest[j][k] - (dist[i][k] - dist[i][j]);
                    if (left > 0)
                        tmp = max(tmp, left / 2 + dist[i][k]);
                }
            }
        }
        ans = min(ans, tmp);
    }
    cout.precision(1);
    cout << fixed << ans;
}