#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  if (s.find("0000000") != -1 || s.find("1111111") != -1)
    cout << "YES";
  else
    cout << "NO";
}