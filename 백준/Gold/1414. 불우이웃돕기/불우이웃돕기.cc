#include <bits/stdc++.h>
using namespace std;

int N, cost = 0;
vector<pair<int, pair<int, int>>> edge;
vector<int> p;

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x < y)
    p[y] = x;
  else
    p[x] = y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  p.resize(N + 1);
  iota(p.begin(), p.end(), 0);
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= N; j++)
      if (s[j - 1] != '0') {
        if (s[j - 1] >= 'a') {
          edge.push_back({s[j - 1] - 'a' + 1, {i, j}});
          cost += s[j - 1] - 'a' + 1;
        } else {
          edge.push_back({s[j - 1] - 'A' + 27, {i, j}});
          cost += s[j - 1] - 'A' + 27;
        }
      }
  }
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      cost -= weight;
      merge(path.first, path.second);
    }
  for (int i = 1; i <= N; i++)
    find(i);
  if (accumulate(p.begin(), p.end(), 0) != N)
    cout << -1;
  else
    cout << cost;
  return 0;
}