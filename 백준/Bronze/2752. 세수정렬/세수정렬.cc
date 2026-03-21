#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> v(3);
  for (int i = 0; i < 3; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  for (int i : v)
    cout << i << ' ';
  return 0;
}