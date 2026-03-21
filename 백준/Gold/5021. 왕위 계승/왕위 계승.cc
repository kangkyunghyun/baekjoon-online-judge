#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, cnt = 0;
  string king;
  cin >> n >> m >> king;
  map<string, int> M;
  vector<int> edges[151], inDegree(151, 0);
  vector<double> blood(151, 0);
  M[king] = cnt++;
  blood[M[king]] = 1;
  while (n--) {
    string name[3];
    for (int i = 0; i < 3; i++)
      cin >> name[i];
    for (int i = 0; i < 3; i++)
      if (M.find(name[i]) == M.end())
        M[name[i]] = cnt++;
    inDegree[M[name[0]]] += 2;
    edges[M[name[1]]].push_back(M[name[0]]);
    edges[M[name[2]]].push_back(M[name[0]]);
  }
  queue<int> q;
  for (int i = 0; i < cnt; i++)
    if (inDegree[i] == 0)
      q.push(i);
  for (int i = 0; i < cnt; i++) {
    int node = q.front();
    q.pop();
    for (int next : edges[node]) {
      blood[next] += blood[node] / 2;
      if (--inDegree[next] == 0)
        q.push(next);
    }
  }
  string s, ans;
  double tmp = 0;
  while (m--) {
    cin >> s;
    if (M.find(s) != M.end() && tmp < blood[M[s]]) {
      tmp = blood[M[s]];
      ans = s;
    }
  }
  cout << ans;
  return 0;
}