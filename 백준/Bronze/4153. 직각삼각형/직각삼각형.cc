#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if (v[0] == 0 && v[1] == 0 && v[2] == 0)
      break;
    if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2])
      cout << "right\n";
    else
      cout << "wrong\n";
  }
  return 0;
}