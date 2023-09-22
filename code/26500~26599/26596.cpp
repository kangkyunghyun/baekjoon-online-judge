#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m;
  cin >> m;
  map<string, int> M;
  for (int i = 0; i < m; i++) {
    string s;
    int x;
    cin >> s >> x;
    if (M.find(s) != M.end())
      M[s] += x;
    else
      M[s] = x;
  }
  for (auto i = M.begin(); i != M.end(); i++)
    for (auto j = M.begin(); j != M.end(); j++)
      if (i != j && floor(1.618 * i->second) == j->second) {
        cout << "Delicious!";
        return 0;
      }
  cout << "Not Delicious...";
  return 0;
}