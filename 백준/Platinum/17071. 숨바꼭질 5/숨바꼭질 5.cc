#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, k;
vector<vector<int>> sister(500001, vector<int>(2, INF));
vector<int> brother(500001, 0);

void bfs() {
  queue<pair<int, int>> q;
  q.push({n, 0});
  sister[n][0] = 0;
  while (!q.empty()) {
    int curr = q.front().first;
    int time = q.front().second;
    q.pop();
    vector<int> nxt{curr * 2, curr - 1, curr + 1};
    for (int next : nxt)
      if (next >= 0 && next <= 500000)
        if (sister[next][(time + 1) % 2] > time + 1) {
          q.push({next, time + 1});
          sister[next][(time + 1) % 2] = time + 1;
        }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  bfs();
  int step = 1;
  while (k < 500001) {
    if (sister[k][brother[k] % 2] <= brother[k]) {
      cout << brother[k];
      return 0;
    }
    if (k + step < 500001)
      brother[k + step] = brother[k] + 1;
    k += step;
    step++;
  }
  cout << -1;
  return 0;
}