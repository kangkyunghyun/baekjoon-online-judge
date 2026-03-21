#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> v(4);
  for (int i = 0; i < 4; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  int ans = v[0] + v[3] - v[1] - v[2];
  cout << abs(ans);
  return 0;
}