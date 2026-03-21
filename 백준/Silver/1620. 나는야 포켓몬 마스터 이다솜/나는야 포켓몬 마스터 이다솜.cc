#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  map<string, int> M;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    M.insert(make_pair(s, i + 1));
    v.push_back(s);
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (s[0] >= 65 && s[0] <= 90)
      cout << M[s] << '\n';
    else
      cout << v[stoi(s) - 1] << '\n';
  }
  return 0;
}