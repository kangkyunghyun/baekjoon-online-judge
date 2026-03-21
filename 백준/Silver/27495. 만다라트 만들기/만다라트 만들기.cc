#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> graph(9, vector<string>(9, ""));
int cnt = 1;

void func(int x, int y) {
  cout << "#" << cnt << ". " << graph[x][y] << '\n';
  vector<string> tmp;
  for (int i = x - 1; i <= x + 1; i++)
    for (int j = y - 1; j <= y + 1; j++)
      if (i == x && j == y)
        continue;
      else
        tmp.push_back(graph[i][j]);
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < 8; i++) {
    cout << "#" << cnt << "-" << i + 1 << ". " << tmp[i] << '\n';
  }
  cnt++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      cin >> graph[i][j];
  int d[] = {1, 4, 7};
  vector<pair<string, pair<int, int>>> v;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (i == 1 && j == 1)
        continue;
      else
        v.push_back({graph[d[i]][d[j]], {d[i], d[j]}});
  sort(v.begin(), v.end());
  for (auto i : v) {
    int x = i.second.first;
    int y = i.second.second;
    func(x, y);
  }
  return 0;
}