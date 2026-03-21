#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, cnt = 1;
  bool isNo = 0;
  cin >> n;
  vector<int> v;
  vector<char> ans;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (cnt <= x) {
      v.push_back(cnt);
      ans.push_back('+');
      cnt++;
    }
    if (v.back() == x) {
      v.pop_back();
      ans.push_back('-');
    } else {
      isNo = 1;
      break;
    }
  }
  if (isNo)
    cout << "NO\n";
  else
    for (char e : ans)
      cout << e << '\n';
  return 0;
}