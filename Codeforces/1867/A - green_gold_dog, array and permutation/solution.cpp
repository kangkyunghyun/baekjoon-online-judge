#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back({x, i});
    }
    sort(a.begin(), a.end(), greater<>());
    for (int i = 0; i < n; i++) {
      b.push_back({i + 1, a[i].second});
    }
    sort(b.begin(), b.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    for (auto i : b)
      cout << i.first << ' ';
    cout << '
';
  }
  return 0;
}