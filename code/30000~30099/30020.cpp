#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  if (a < b) {
    cout << "NO";
    return 0;
  }
  vector<string> ans;
  while (a - 1 != b) {
    ans.push_back("aba");
    a -= 2;
    b--;
    if (a <= 0 || b <= 0) {
      cout << "NO";
      return 0;
    }
  }
  string tmp = "a";
  while (--a) {
    tmp += "ba";
  }
  ans.push_back(tmp);
  cout << "YES\n";
  cout << ans.size() << '\n';
  for (string i : ans)
    cout << i << '\n';
}