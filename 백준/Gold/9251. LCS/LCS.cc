#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  vector<vector<int>> graph(a.size() + 1, vector<int>(b.size() + 1, 0));
  int ans = 0;
  for (int i = 1; i <= a.size(); i++)
    for (int j = 1; j <= b.size(); j++)
      if (a[i - 1] == b[j - 1])
        graph[i][j] = graph[i - 1][j - 1] + 1;
      else
        graph[i][j] = max(graph[i - 1][j], graph[i][j - 1]);
  cout << graph[a.size()][b.size()];
  return 0;
}