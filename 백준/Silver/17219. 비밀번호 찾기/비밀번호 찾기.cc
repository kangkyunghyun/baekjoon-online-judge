#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  map<string, string> M;
  while (n--) {
    string link, pw;
    cin >> link >> pw;
    M.insert(make_pair(link, pw));
  }
  while (m--) {
    string s;
    cin >> s;
    cout << M[s] << '\n';
  }
  return 0;
}