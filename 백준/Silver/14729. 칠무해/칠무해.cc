#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<float> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  cout.precision(3);
  cout << fixed;
  for (int i = 0; i < 7; i++)
    cout << v[i] << '\n';
  return 0;
}