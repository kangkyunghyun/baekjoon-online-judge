#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    while (!v.empty() && v.back() < s[i] - '0' && k) {
      v.pop_back();
      k--;
    }
    v.push_back(s[i] - '0');
  }
  while (k--)
    v.pop_back();
  for (int i : v)
    cout << i;
  cout << '\n';
  return 0;
}