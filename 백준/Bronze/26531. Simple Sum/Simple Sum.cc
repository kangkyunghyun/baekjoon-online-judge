#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int a, b, c;
  char t;
  cin >> a >> t >> b >> t >> c;
  if (a + b == c)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}