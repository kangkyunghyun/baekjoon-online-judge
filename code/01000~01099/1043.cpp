#include <bits/stdc++.h>
using namespace std;

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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  p.resize(n + 1);
  iota(p.begin(), p.end(), 0);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    p[x] = 0;
  }
  vector<vector<int>> party;
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    vector<int> tmp(num);
    cin >> tmp[0];
    for (int j = 1; j < num; j++) {
      cin >> tmp[j];
      merge(tmp[0], tmp[j]);
    }
    party.push_back(tmp);
  }
  int ans = m;
  for (int i = 0; i < m; i++)
    for (int j : party[i])
      if (find(j) == 0) {
        ans--;
        break;
      }
  cout << ans;
  return 0;
}