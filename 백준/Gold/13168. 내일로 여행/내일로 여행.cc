#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, R, M, K;
  double dist1[101][101], dist2[101][101];
  map<string, int> m;
  cin >> N >> R;
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    m[s] = i;
  }
  cin >> M;
  vector<int> v;
  for (int i = 1; i <= M; i++) {
    string s;
    cin >> s;
    v.push_back(m[s]);
  }
  cin >> K;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      dist1[i][j] = i == j ? 0 : INF;
      dist2[i][j] = i == j ? 0 : INF;
    }
  while (K--) {
    string t, s, e;
    double c;
    cin >> t >> s >> e >> c;
    int u = m[s], v = m[e];
    dist1[u][v] = min(dist1[u][v], c);
    dist1[v][u] = min(dist1[v][u], c);
    if (t == "Mugunghwa" || t == "ITX-Saemaeul" || t == "ITX-Cheongchun") {
      dist2[u][v] = 0;
      dist2[v][u] = 0;
    } else if (t == "S-Train" || t == "V-Train") {
      dist2[u][v] = min(dist2[u][v], c / 2);
      dist2[v][u] = min(dist2[v][u], c / 2);
    } else {
      dist2[u][v] = min(dist2[u][v], c);
      dist2[v][u] = min(dist2[v][u], c);
    }
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) {
        dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
        dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
      }
  double sum1 = 0, sum2 = 0;
  for (int i = 0; i < M - 1; i++) {
    int s = v[i], e = v[i + 1];
    sum1 += dist1[s][e];
    sum2 += dist2[s][e];
  }
  cout << (sum1 > sum2 + R ? "Yes\n" : "No\n");
  return 0;
}