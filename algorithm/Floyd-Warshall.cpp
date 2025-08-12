// Floyd-Warshall O(N^3)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, dist[101][101];
    cin >> N >> M;
    // dist 배열 초기화
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = i == j ? 0 : INF;
    // 간선 정보 입력
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    // 플로이드 워셜
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    // 실제 최단 경로
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
        cout << '\n';
    }
    return 0;
}