#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    string a = s.substr(0, i);
    string b = s.substr(n - i, i);
    int cnt = 0;
    for (int j = 0; j < i; j++)
      if (a[j] != b[j])
        cnt++;
    if (cnt == 1) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}