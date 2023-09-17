#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k, l;
  cin >> n;
  set<char> s;
  while (n--) {
    char c;
    cin >> c;
    s.insert(c);
  }
  cin >> m;
  while (m--) {
    char c;
    cin >> c;
    s.insert(c);
  }
  cin >> k;
  while (k--) {
    char c;
    cin >> c;
    if (s.find(c) != s.end())
      s.erase(s.find(c));
  }
  cin >> l;
  string S;
  cin.ignore();
  getline(cin, S);
  for (int i = 0; i < l; i++) {
    if (s.find(S[i]) != s.end()) {
      S[i] = ' ';
    }
  }
  stringstream ss;
  ss.str(S);
  string tmp;
  while (ss >> tmp)
    cout << tmp << '\n';
}