#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  map<string, bool> M;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    M[str] = true;
  }
  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    if (M[str])
      cnt++;
  }
  cout << cnt << '\n';
  return 0;
}