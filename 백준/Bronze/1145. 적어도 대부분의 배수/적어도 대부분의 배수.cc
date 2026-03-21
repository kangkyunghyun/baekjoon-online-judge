#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> v(5);
  for (int i = 0; i < 5; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  int n = v[0];
  while (1) {
    int cnt = 0;
    for (int i = 0; i < 5; i++)
      if (n % v[i] == 0)
        cnt++;
    if (cnt >= 3)
      break;
    n++;
  }
  cout << n;
  return 0;
}