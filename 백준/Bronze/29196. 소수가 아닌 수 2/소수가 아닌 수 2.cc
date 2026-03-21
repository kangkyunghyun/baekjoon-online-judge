#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string k;
  cin >> k;
  int idx = k.find('.');
  cout << "YES\n";
  cout << (k.substr(0, idx) == "0" ? "" : k.substr(0, idx)) << k.substr(idx + 1) << " 1";
  for (int i = 0; i < k.size() - 2; i++)
    cout << '0';
  return 0;
}