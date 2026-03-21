#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  cin >> n;
  set<string> s;
  while (n--) {
    string a;
    cin >> a;
    if (a == "ENTER") {
      ans += s.size();
      s.clear();
    } else {
      s.insert(a);
    }
  }
  ans += s.size();
  cout << ans;
  return 0;
}