#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    cout << "String #" << i << '\n';
    for (char c : s)
      cout << (c == 90 ? 'A' : (char)(c + 1));
    cout << "\n\n";
  }
  return 0;
}