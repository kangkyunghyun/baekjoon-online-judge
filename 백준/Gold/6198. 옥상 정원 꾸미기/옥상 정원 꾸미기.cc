#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long ans = 0;
  cin >> n;
  vector<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (!s.empty() && s.back() <= x)
      s.pop_back();
    ans += (long long)s.size();
    s.push_back(x);
  }
  cout << ans;
  return 0;
}