#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= 10 || a + c >= 10 || b + c >= 10)
      cout << "yes
";
    else
      cout << "no
";
  }
  return 0;
}