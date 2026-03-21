#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  map<string, string> M;
  while (n--) {
    string team, name;
    int num;
    cin >> team >> num;
    while (num--) {
      cin >> name;
      M.insert({name, team});
    }
  }
  while (m--) {
    string quiz;
    int type;
    cin >> quiz >> type;
    if (type == 0) {
      for (auto elem : M)
        if (elem.second == quiz)
          cout << elem.first << '\n';
    } else {
      cout << M[quiz] << '\n';
    }
  }
  return 0;
}