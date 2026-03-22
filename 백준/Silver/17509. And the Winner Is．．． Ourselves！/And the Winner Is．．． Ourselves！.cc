#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int, int>> a;
  for (int i = 0; i < 11; i++) {
    int d, v;
    cin >> d >> v;
    a.push_back({d, v});
  }
  sort(a.begin(), a.end());
  int time = 0, ans = 0;
  for (int i = 0; i < 11; i++) {
    time += a[i].first;
    ans += time + a[i].second * 20;
  }
  cout << ans;
  return 0;
}