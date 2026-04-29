#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    int n;
    cin >> n >> s;
    map<string, int> M;
    for (int i = 0; i < n - 1; i++) {
      M[s.substr(i, 2)]++;
    }
    cout << M.size() << '
';
  }
  return 0;
}