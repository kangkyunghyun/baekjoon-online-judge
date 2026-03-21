#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int p, cnt = 0;
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2] >> p;
    for (int i : v)
      if (!(i % p))
        cnt++;
    if (cnt >= 2)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}