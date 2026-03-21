#include <bits/stdc++.h>
using namespace std;

vector<int> p, s;

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  if (x > y)
    swap(x, y);
  s[x] += s[y];
  p[y] = x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    p.resize(2 * n);
    iota(p.begin(), p.end(), 0);
    s.resize(2 * n);
    fill(s.begin(), s.end(), 1);
    map<string, int> M;
    while (n--) {
      string a, b;
      cin >> a >> b;
      if (M.find(a) == M.end())
        M[a] = M.size();
      if (M.find(b) == M.end())
        M[b] = M.size();
      merge(M[a], M[b]);
      cout << s[find(M[a])] << '\n';
    }
  }
  return 0;
}